// Szablony są potężnym narzędziem które pozwala na pisanie funkcji i klas w sposób ogólny, tak aby mogły one pracować z różnymi typami danych bez potrzeby ponownego pisania kodu dla każdego typu.
// Zwiększa ponowne wykorzystanie kodu, pomaga w utrzymaniu czystości i klarowności kodu.

// Szablon funkcji definiuje ogólny wzór dla funkcji, który może być używany z różnymi typami danych. Kompilator automatycznie generuje specjalizację funkcji dla konkretnego typu danych, gdy jest ona wywoływana.
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << max<int>(1, 2) << std::endl;           // Użycie z typem int
    std::cout << max<double>(3.5, 2.5) << std::endl;    // Użycie z typem double
    std::cout << max<char>('a', 'b') << std::endl;      // Użycie z typem char
    return 0;
}

// Szablony klas
// Podonmie jak szablony funkcji, szablony klas pozwalają na definiowanie klas w sposób ogólny, aby mogły one pracować z różnymi typami danych.

template <typename T>
class Box {
private:
    T content;
public:
    void set(T newContent) {
        content = newContent;
    }

    T get() const {
        return content;
    }
};

int main() {
    Box<int> intBox;
    intBox.set(123);
    std::cout << intBox.get() << std::endl; // Wypisuje 123

    Box<std::string> stringBox;
    stringBox.set("Test");
    std::cout << stringBox.get() << std::endl; // Wypisuje "Test"
    return 0;
}

// Kluczowe informacje o szablonach:
// dedukcja typów - kompilator jest w stanie wydedukować typ argumentów szablonu na podstawie kontekstu wywołania, co pozwala na pominięcie jawnej specyfikacji typu.
// specjalizacja - można definiować specjalizacje szablonów dla konkretnych typów dancyh, które zachowują się inaczej niż ogólny szablon
// szablony a efektywność - szablony mogą zwiększyć rozmiar kodu wynikowego, ponieważ dla każdego typu danych generowana jest odrębna instancja funkcji/klasy. Jenakże kompilatory są zoptymalizowane, aby minimalizować ten efekt.
