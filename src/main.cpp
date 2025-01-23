#include <fmt/core.h>

int main() {
    int x = 42;
    double y = 3.14159;

    // Форматированный вывод
    fmt::print("The answer is {} and pi is {:.2f}\n", x, y);

    return 0;
}