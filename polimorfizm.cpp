/*
RAII to potężne narzędzie w C++ do zarządzania zasobami.
Korzyści: Zapobiega wyciekom zasbów, zapewnia bezpieczeństwo wyjątków i promuje czytelniejszy kod.

Polimorfizm: metody wirtualne to metody w klasach bazowych, które mogą być przesłonięte w klasach pochodnych
*/

class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing shape..." << std::endl;
    }
};

class Circle : public Shape{
public:
    void draw() override{
        std::cout << "Drawing circle..." << std::endl;
    }
};

int main(){
    Shape* shapePtr = new Circle();
    shapePtr->draw(); //Wywołanie polimorficznej metody draw()
    delete shapePtr;
    return 0;
}

//Uzywaj modyfikatora virtual przy definiowaniu metod w klasie bazowej, które mają być przesłonięte w klasach pochodnych.
//Zawsze stosuj modyfikator override przy przesłanianiu metod, aby uniknąć błędów w przypadku nieprawidłowej sygnatury funkcji
