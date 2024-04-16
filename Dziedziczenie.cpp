// Dziedziczenie w C++ jest mechanizmem który umożliwia tworzenie nowych klas( klas pochodnych)
class Animal {
public:
    void eat() {
        std::cout<< "Animal is eating..." << std::endl;
    }
};

class Dog : public Animal {
public:
    void bark(){
        std::cout << "Dog is barking..." << std::endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat();    // Dziedziczenie metody eat() z klasy Animal
    myDog.bark();
    return 0;
}
