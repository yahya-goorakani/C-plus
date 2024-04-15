#include <iostream>
#include "polynomial.h"

int main() {
    const Polynomial a({-1, 0, 0, 0, 1});
    Polynomial b({-1, 0, 1});
    Polynomial c({1, 1, 1, 1, 1, 1, 1, 1});

    std::cout << "a[0]: " << a[0] << std::endl;
    b[100] = 3;

    std::cout << "a: " << a << std::endl;
    std::cout << "-a: " << -a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "a + b: " << a + b << std::endl;
    std::cout << "a - b: " << a - b << std::endl;
    std::cout << "a * b: " << a * b << std::endl;
    std::cout << "a / b: " << a / b << std::endl;
    std::cout << "a % b: " << a % b << std::endl;
    std::cout << "b / a: " << b / a << std::endl;
    std::cout << "b % a: " << b % a << std::endl;

    c = std::move(b);
    std::cout << "c (after move from b): " << c << std::endl;

    return 0;
}
