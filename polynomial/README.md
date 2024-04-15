# Polynomial Class in C++

This repository contains a C++ implementation of a Polynomial class. The Polynomial class allows you to create, manipulate, and perform operations on polynomials of any degree. The class supports addition, subtraction, multiplication, division, and evaluation of polynomials.

## Features

- **Constructor Overloads**: Supports construction from an array of coefficients, a list of coefficients, or an array of floats.
- **Copy and Move Semantics**: Implements copy constructor and move constructor for efficient memory management.
- **Arithmetic Operations**: Supports addition, subtraction, multiplication, division, and modulo operations.
- **Evaluation**: Evaluate the polynomial at a specific value of x.
- **Indexing**: Access and modify polynomial coefficients using index operator.
- **String Representation**: Convert polynomial to a human-readable string format.

## Installation

To use the Polynomial class in your C++ project, you can clone this repository or download the `polynomial.h` and `polynomial.cpp` files and include them in your project.

```bash
git clone https://github.com/yahya-goorakani/c-plus.git

```

## Usage
- Here's an example of how to use the Polynomial class:
```bash
#include <iostream>
#include "polynomial.h"

int main() {
    // Create polynomials
    const Polynomial a({-1, 0, 0, 0, 1});
    Polynomial b({-1, 0, 1});
    Polynomial c({1, 1, 1, 1, 1, 1, 1, 1});

    // Evaluate polynomial
    std::cout << "a[0]: " << a[0] << std::endl;

    // Modify coefficient
    b[100] = 3;

    // Perform arithmetic operations
    std::cout << "a + b: " << a + b << std::endl;
    std::cout << "a - b: " << a - b << std::endl;
    std::cout << "a * b: " << a * b << std::endl;
    std::cout << "a / b: " << a / b << std::endl;
    std::cout << "a % b: " << a % b << std::endl;

    // Move assignment
    c = std::move(b);
    std::cout << "c (after move from b): " << c << std::endl;

    return 0;
}
```
## Contributing
- If you'd like to contribute to this project, feel free to fork the repository and submit a pull request. Please make sure to follow the coding style and add appropriate tests for your changes.

## License
- This project is licensed under the MIT License. See the LICENSE file for more details.

# Contact
- For any questions or suggestions, please feel free to contact me at yahya.goorakani@example.com.