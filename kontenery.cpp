#include <iostream>
#include <deque>
#include <list>
#include <map>
#include <set>

int main()
{
    //deque
    std::deque<int> myDeque;
    
    // Dodawanie elementow na koncu i poczatku
    myDeque.push_back(10); //deque: 10
    myDeque.push_front(5);  //deque 5,10
    
    //Usuwanie elementow z konca i poczatku
    myDeque.pop_back(); //deque: 5
    myDeque.pop_front();   //deque: pusty
    
    //Losowy dostep do elementow
    myDeque.push_back(15);
    myDeque.push_back(20);
    std::cout<<"Element na pozycji 1: "<<myDeque[1]<<std::endl;
    
    //Rozmiar deque
    std::cout<<"Rozmiar deque: "<<myDeque.size()<<std::endl;

    //list
    std::list<int> myList;
    
    //Wstawianie elementow
    myList.push_back(10); //myList: 10
    myList.push_front(5); //myList: 5, 10
    auto it = myList.begin();
    advance(it, 1); //Przesun iterator na druga pozycje
    myList.insert(it, 7); // myList: 5, 7, 10
    
    //Usuwanie elementow
    myList.pop_front(); //myList: 7, 10
    myList.erase(++myList.begin()); //myList: 7
    
    //Iteracja po liscie
    std::cout<<"Elementy listy: ";
    
    for(int n : myList) {
        std::cout<<n<<" ";
    }
    std::cout <<std::endl;

    //map
    std::map<std::string, int> ocenyStudentow;

    //Wstawianie wartosci
    ocenyStudentow["Jan Kowalski"] = 5;
    ocenyStudentow["Anna Nowak"] = 4;

    //Aktualizacja wartosci
    ocenyStudentow["Jan Kowalski"] = 6;

    //Dostep do wartosci
    std::cout<<"Ocena Jana Kowalskiego: "<<ocenyStudentow["Jan Kowalski"]<<std::endl;

    //Wyszukiwanie klucza
    if (ocenyStudentow.find("Anna Nowak") != ocenyStudentow.end()) {
        std::cout<<"Ocena Anny Nowak: "<<ocenyStudentow["Anna Nowak"]<<std::endl;
    }

    //Iteracja po mapie
    for(auto& para : ocenyStudentow) {
        std::cout <<"Student: "<<para.first<<", Ocena: "<<para.second<<std::endl;
    }

    //set
    std::set<int> liczby;

    //Wstawianie elementow
    liczby.insert(10);
    liczby.insert(5);
    liczby.insert(20);
    liczby.insert(10); //Ten element nie zostanie dodany, ponieważ jest już obecny

    //Sprawdzanie obecności elementu
    if(liczby.find(5) != liczby.end()) {
        std::cout<<"Element 5 znajduje się w zbiorze." <<std::endl;
    }

    //Iteracja po zbiorze
    std::cout<<"Elementy zbioru: ";
    for(int liczba : liczby) {
        std::cout<<liczba<<" ";
    }
    std::cout<<std::endl;

    return 0;
}
