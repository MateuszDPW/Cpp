#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

// Struktura do przechowywania pojedynczego pomiaru
struct Measurement{
    double voltage; // napięcie
    double current; // natężenie
};

// Struktura do przechowywania znacznika czasu
struct TimePeriod{
    int year, month, day, hour, minute, second;
};

// Funkcja do parsowania znacznika czasu w formacie YYYYMMDDHHmmSS
TimePeriod parseTimestamp(const string& timestamp){
    TimePeriod tp;
    tp.year = stoi(timestamp.substr(0, 4));
    tp.month = stoi(timestamp.substr(4, 2));
    tp.day = stoi(timestamp.substr(6, 2));
    tp.hour = stoi(timestamp.substr(8, 2));
    tp.minute = stoi(timestamp.substr(10, 2));
    tp.second = stoi(timestamp.substr(12, 2));
    return tp;
}

// Funkcja do formatowania okresu czasu w zależności od granularności
string formatTimePeriod(const TimePeriod& tp, int granularity){
    ostringstream oss;
    oss << setw(4) << setfill('0') << tp.year
        << setw(2) << setfill('0') << tp.month
        << setw(2) << setfill('0') << tp.day
        << setw(2) << setfill('0') << tp.hour;
    
    // Dodaj minutę w zależności od poziomu granularności
    if (granularity >= 2){
        oss << setw(2) << setfill('0') << (tp.minute / 30) * 30;
    }
    
    // Dodaj pięciominutowy segment w zależności od poziomu granularności
    if (granularity == 3){
        oss << setw(2) << setfill('0') << (tp.minute / 5) * 5;
    }
    return oss.str();
}

// Funkcja do przetwarzania pliku JSON z danymi
void processFile(const string& filename, int granularity){
    ifstream inputFile(filename);
    if (!inputFile.is_open()){
        cerr << "Nie można otworzyć pliku!" << endl;
        return;
    }

    // Mapa do przechowywania danych pomiarowych zgrupowanych według okresów czasowych
    map<string, vector<Measurement>> dataMap;
    string line;
    
    // Odczyt danych z pliku linia po linii
    while (getline(inputFile, line)){
        size_t dataPos = line.find("\"data\": {");
        if (dataPos == string::npos) continue;
        
        size_t startPos = dataPos + 9; // Przesuń się za "data": {
        size_t endPos = line.rfind("}"); // Znajdź ostatnią zamykającą klamrę
        
        if (endPos == string::npos) continue; // Pomiń niekompletne wiersze

        string dataContent = line.substr(startPos, endPos - startPos);
        
        stringstream ss(dataContent);
        string measurement;
        
        // Odczyt poszczególnych pomiarów
        while (getline(ss, measurement, ',')){
            try{
                size_t keyEnd = measurement.find("\":");
                if (keyEnd == string::npos) continue; // Pomiń niekompletne pomiary

                string timestamp = measurement.substr(1, keyEnd - 1);
                size_t uPos = measurement.find("\"U\":") + 4;
                if (uPos == string::npos) continue; // Pomiń niekompletne pomiary

                size_t uEnd = measurement.find(",", uPos);
                if (uEnd == string::npos) continue; // Pomiń niekompletne pomiary

                double voltage = stod(measurement.substr(uPos, uEnd - uPos));
                size_t iPos = measurement.find("\"I\":") + 4;
                if (iPos == string::npos) continue; // Pomiń niekompletne pomiary

                double current = stod(measurement.substr(iPos));

                // Przekształć znacznik czasu na strukturę TimePeriod
                TimePeriod tp = parseTimestamp(timestamp);
                // Sformatuj klucz dla okresu czasowego
                string periodKey = formatTimePeriod(tp, granularity);
                // Dodaj pomiar do odpowiedniego okresu czasowego
                dataMap[periodKey].push_back({voltage, current});
            } catch (const std::exception& e){
                // Pomiń aktualny pomiar w przypadku wystąpienia błędu
                continue;
            }
        }
    }
    
    inputFile.close();
    
    // Oblicz i wyświetl średnie wartości napięcia i natężenia dla każdego okresu czasowego
    for (const auto& [key, measurements] : dataMap){
        double sumVoltage = 0.0;
        double sumCurrent = 0.0;
        
        for (const auto& m : measurements){
            sumVoltage += m.voltage;
            sumCurrent += m.current;
        }
        
        double avgVoltage = sumVoltage / measurements.size();
        double avgCurrent = sumCurrent / measurements.size();
        
        cout << "Okres: " << key << ", Średnie napięcie: " << avgVoltage
             << ", Średnie natężenie: " << avgCurrent << endl;
    }
}

int main(int argc, char* argv[]){
    if (argc != 4){
        cerr << "Użycie: " << argv[0] << " <nazwa_pliku> -t <h|m30|m5>" << endl;
        return 1;
    }
    string filename = argv[1];
    string option = argv[3];
    int granularity = 0;
    
    if (option == "h"){
        granularity = 1;
    } else if (option == "m30"){
        granularity = 2;
    } else if (option == "m5"){
        granularity = 3;
    } else{
        cerr << "Nieprawidłowa opcja. Użyj 'h', 'm30' lub 'm5'." << endl;
        return 1;
    }
    
    // Przetwórz plik z danymi na podstawie określonej granularności
    processFile(filename, granularity);
    
    return 0;
}
