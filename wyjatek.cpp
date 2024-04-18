// ten przykład demonstruje, jak rzucić wyjątek przy użyciu throw, a następnie przechwycić go za pomocą try i catch
#include <iostream>
#include <stdexcept> // do obsługi wyjątków standardowych

int main() {
	try {
		//Symulacja błędu - rzucamy wyjątek
		throw std::runtime_error("Wystąpił błąd!");
	
	} catch (const std::runtime_error& e){
		//Przechowujemy wyjątek i wyświetlamy jego wiadomość
		std::cout << "Wyjątek: " << e.what() << std::endl;
		}
	return 0;
}

// przykład użycia catch() do przechwycenia dowolnego wyjątku

try {
    // kod, który może rzucić dowolny wyjątek
} catch (const std::exception& e) {
    // Obsługa wyjątków standardowych
    std::cout << "Wyjątek standardowy: " << e.what() << std::endl;
} catch(...) {
    // obsługa dowolnych wyjątków
    std::cout<<"Nieznany wyjątek przechwycony" << std::endl;
}

// Hierarchia
// std::exception - klasa bazowa dla wszystkich standardowych wyjątków. Zawiera wirtualną funkcję what(), która zwraca komunikat o błędzie. Jest bardzo ogólna.
// std::logic_error - oznacza błędy w logice programu, które teoretycznie można wykryć przed uruchomieniem programu.
// std::runtime_error - reprezentuje błędy, które występują podczas działania programu i nie mogą być łatwo przewidziane przed jego uruchomieniem.
// std::bad_alloc - wyjątek rzucany przez mechanizm alokacji pamięci.
// std::bad_cast - rzucany przez dynamiczne rzutowanie typów, gdy rzutowanie nie może się powieść.
// 
// Kiedy używać których wyjątków?
// std::logic_error i jego pochodne powinny być używane do sygnalizowania błędów, które wynikają z błędów w logice programu.
// std::runtime_error i jego pochodne są odpowiednie dla błędów, które występują podczas działania programu i nie mogą być łatwo przewidziane ani uniknięte przed uruchomieniem
// 
// Przykład użycia RAII:
class Resoruce{
public:
    Resource() {std::cout << "Zasób alokowany\n";}
    -Resource() {std::cout << "Zasób zwalniany\n";}
};

int main() {
    try{
        Resource r;
        throw std::runtime_error("Błąd");
    } catch(...) {
        std::cout << "Wyjątek przechwycony\n";
    }
    // Zasób zostanie zwolniony tutaj, niezależnie od wyjątku
    return 0;
}

// Użycie własnych klas wyjątków
#include <iostream>
#include <exception>

// Definicja własnej klasy wyjątków
// pokazano, jak można zdefiniować własne klasy wyjątków, dziedzicząc po klasach wyjątków standardowej biblioteki C++.
// Własne klasy wyjątków mogą być użyteczne, gdy chcemy dostarczyć dodatkowe informacje w naszych wyjątkach.
class MyException : public std::exception {
public:
    MyException(const char* message) : msg_(message) {}

    const char* what() const noexcept override {
        return msg_;
    }
private:
    const char* msg_;
};

int main() {
    try {
        // rzucamy nasz własny wyjątek
        throw MyException("Wystąpił mój wyjątek!");
    } catch (const MyException& e) {
        // Przechwytujemy i osbługujemy nasz własny wyjątek
        std::cout << "Mój wyjątek mówi: " << e.what() << std::endl;
    }
    return 0;
}

// Obsługa różnych typów wyjątków
// w tym przykładzie przedstawiono, jak obsłużyć różne typy wyjątków w jednym bloku try za pomocą wielu bloków catch.
#include <iostream>
#include <stdexcept>
#include <vector>

int main() {
    try {
        std::vector<int> vec;
        // Symulacja błędu - dostęp do nieistniejącego elementu
        std::cout << vec.at(10);
    } catch (const std::out_of_range& e) {
        // Specyficzna obsługa wyjątku związana z zakresem
        std::cout << "Wyjątek zakresu: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        // Ogólna obsługa innych wyjątków
        std::cout << "Wyjątek standardowy: " << e.what() << std::endl;
    }
    return 0;
}
