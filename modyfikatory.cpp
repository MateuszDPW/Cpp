// w cpp constexpr i consteval są modyfikatorami, które umożliwiają wykonywanie obliczeń w czasie kompilacji.
// constexpr wskazuje, że zmienna musi mieć wartość stałą, która jest znana w czasie kompilacji
// lub że funkcja jest zdolna de generowania wartości stałej w czasie kompilacji, jeśli wszystkie jej argumenty są stałe.

constexpr int factorial(int n) {
    return n <= 1 ? 1 : n * factorial(n -1);
}

int main() {
    constexpr int val = factorial(5); // Obliczane w czasie kompilacji
    return 0;
}

// consteval zapewnia że funkcja musi być wywoływana i ewluowana w czasie kompilacji, co oznacza, że wszystkie wywołania funkcji consteval są ewaluowane w czasie kompilacji.
// nie można jej używać w czasie wykonania.
// Jest to sposób na gwarancję


// constexpr pozwala na obliczenia w czasie kompilacji, ale również dopuszcza użycie w czasie wykanania, jeśli jest to konieczne.
//consteval wymusza obliczenia wyłącznie w czasie kompilacji
