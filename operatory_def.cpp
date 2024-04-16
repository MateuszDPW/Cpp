//  Przyklad 1

class Vector{
    public:
        float x, y;

        Vector(float x, float y) : x(x), y(y) {}

        // Przeładowanie operatora + jako metoda klasy
        Vector operator+(const Vecotr& other) const {
            return Vector(x + other.x, y + other.y);
    }
};

#include <iostream>

// (Tutaj umieszczamy definicję klasy Vector)

int main() {
    Vector v1(1.0, 2.0), v2(3.0, 4.0);
    Vector v3 = v1 + v2; // Używamy przeładowanego operatora +

    std::cout << "v3: (" << v3.x << ", " << v3.y << ")" << std::endl;
    return 0;
}

//  Przyklad 2

#include <numeric> // Dla std::gcd (C++17)

class Fraction {
private:
    int numerator, denominator;

public:
    Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
        // Normalizacja ułamka
        int gcd = std::gcd(numerator, denominator);
        this ->numerator /= gcd;
        this ->denominator /= gcd;
    }
    // Przeładowanie operatora *
    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other. denominator);
    }

    //Przeładowanie operatora ==
    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
}
};

#include <iostream>

// Tutaj umieszczamy definicję klasy Fraction

int main(){
    Fraction f1(1,2), f2(2,3);
    Fraction result = f1*f2;    //mnożzenie ułamków
    std::cout << "Result " << result.numerator << "/" << result.denominator << std::endl;

    Fraction f3(2,4);
    if f1 == f3 {
        std::cout << "f1 and f3 are equal." << std::endl;
    } else {
        std::cout << "f1 and f3 are not equal." << std::endl;
    }
    return 0;
}
