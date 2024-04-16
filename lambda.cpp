//  lambda - anonimowe funkcje, które mogą być używane do tworzenia szybkich i zwięzłych operacji na miejscu. Są przydatne w STL.

auto sum = [](int a, int b) -> int { return a+b;};
std::cout <<sum(5,3) // wypisze 8

// klauzula capture([]) kontroluje które zmienne z zwenętrznego zakresu są chwytane wewnątrz wyrażenia lambda. możliwe opcje to chwytanie przez wartość ([=]), przez refenrencję ([&]), mieszanie formy, oraz chwytanie konkretnych zmiennych
#include <iostream>

int main() {
    int x = 4;
    auto access_by_value = [=]() { std::cout <<"Dostęp przez wartość: " <<x << std::endl;};
    auto access_by_reference = [&]() { std::cout <<"Dostęp przez referencję przed zmianą: " << x << " "; ++x; std::cout << "po zmianie: "<< x << std::endl; };

    access_by_value(); // Dostęp przez wartość, x pozostaje niezmienione
    access_by_reference(); // Dostęp rzez referencję, x jest modyfikowalne
    return 0;
}
// wyrażenia lambda są niezastąpione w algorytmach STL, umożliwiając definicję niestandardowych operacji bez potrzeby tworzenia oddzielnych funkcji. są szczególnie użyteczne w algorytmach takich jak sort, for_each, transform
#include <algorithm>
#include <vector>
#include <iostream>

int main(){
    std::vector<int> vec{4,1,3,5,2};
    std::for_each(vec.begin(), vec.end(), [](int& n) { n *= 2; });

    std::cout <<"Elementy po podwojeniu: ";
    for(int n : vec) {
        std::cout << n << ' ';
    }
    std:: cout << std::endl;
    return 0;
}

// zaawansowane użycie wyrażeń lambda

#include <algorithm>
#include <vector>
#include <iostream>

int main(){
    std::vector<int> vec{4,1,3,5,2};
    int threshold = 3;
    vec.erase(std::remove_if(vec.begin(), vec.end(), [threshold](int n) { return n < threshold;}), vec. end());

    std::cout <<"Elementy większe lub równe 3: ";
    for(int n : vec) {
        std::cout << n << ' ';
    }
    std:: cout << std::endl;
    return 0;
}

//zadanie 1

#include <algorithm>
#include <vector>
#include <iostream>

int main(){
    // Dane wejściowe:
    std::vector<int> vec{4, 1, 3, 5, 2, 6, 7, 8, 9, 10};
    std::vector<int> filtered;
    std::vector<int> transformed;

    //Filtrowanie: Usuwamy liczby nieparzyste
    std::copy_if(input.begin(), input.end(), std::back_inserter(filtered), [](int x) { return x % 2 == 0; }); //wyrażenie lambda sprawdza parzystość

    // Transformacja: Podwajamy wartości
    std::transform(filtered.begin(), filtered.end(), std::back_inserter(transformed), [](int x) { return x * 2;}); // wyrażenie lambda podwaja wartość

    // wyświetlenie wyników
    std::cout<< "Przefiltrowane i przetransformowane dane: ";
    for(int n : transformed) {
        std::cout << n <<' ';
    }
    std::cout << std::endl;

    return 0;
}
