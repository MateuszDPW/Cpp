//algorytmy STL
//sort()
#include <algorithm>
#include <vector>
#include <iostream>

int main(){
    std::vector<int> vec{4,1,3,5,2};
    std::sort(vec.begin(), vec.end());  //  sort służy do sortowania elementów w kontenerze. domyślnie w rosnącym. Zastosowania: sortowanie danych, przygotowanie danych do operacjiwyszukiwania binarnego, unikatowośc danych
    for(int n : vec) {
        std::cout << n <<' ';
    }
    return 0;
}

//find()

#include <algorithm>
#include <vector>
#include <iostream>

int main(){
    std::vector<int> vec{4,1,3,5,2};
    auto it = std::find(vec.begin(), vec.end(), 3); //  find jest używany do wyszukiwania pierwszego wystąpienia wartości w kontenerze. Zwraca iterator do pierwszego znalezionego elementu lub iterator końca kontenera, jeśli wartość nie została znaleziona. Zastosowania: sprawdzanie obecności elementu, wyszukiwanie danych
    if(it != vec.end()) {
        std::cout << "Znaleziono element: " << *it << '\n';
    } else {
        std::cout << "Element nie został znaleziony.\n";
    }
    return 0;
}

// accumulate()
#include <numeric>
#include <vector>
#include <iostream>

int main(){
    std::vector<int> vec{4,1,3,5,2};
    int sum = std::accumulate(vec.begin(), vec.end(), 0);   //  accumulate jest używany do agregacji(np. sumowania) elementów kontenera, zaczynając od podanej wartości początkowej. Zastosowania: obliczanie sumy elementów, łączenie elementów za pomocą niest. operacji.
    std::cout << "Suma elementów: " << sum << '\n';
    return 0;
}

// partition()
#include <algorithm>
#include <vector>
#include <iostream>

bool is_odd(int n) {return n % 2 == 1; }

int main(){
    std::vector<int> vec{4,1,3,5,2};
    std::partition(vec.begin(), vec.end(), is_odd); // reogarnizuje elementy w kontenerze tak, że elementy spełniające dany predyktat znajdą się przed tymi, które go nie spełniają. Zastosowania: przygotowanie danych do innych operacji, segregowanie danych według kryteriów
    for(int n : vec) {
        std::cout << n << ' ';
    }
    return 0;
}
