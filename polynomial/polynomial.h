#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <initializer_list>
#include <iostream>
#include <utility>

class Polynomial {
private:
    double* coefficients;
    int degree;

    static std::pair<Polynomial, Polynomial> division(Polynomial p1, Polynomial p2);

public:
    Polynomial();
    Polynomial(const Polynomial& other);  // Copy constructor
    Polynomial(Polynomial&& other);       // Move constructor
    Polynomial(double* coeffs, int deg);  // Array of doubles with specified degree
    Polynomial(float* coeffs, int deg);   // Array of floats
    Polynomial(std::initializer_list<double> coeffs);
    ~Polynomial();

    double evaluate(double x) const;

    double& operator[](int i);
    double operator[](int i) const;  // Access without modification
    double at(int i) const;          // Throws an exception

    Polynomial& operator=(const Polynomial& p);  // Copy assignment operator
    Polynomial& operator=(Polynomial&& p);       // Move assignment operator

    friend bool operator==(const Polynomial& p1, const Polynomial& p2);
    friend bool operator!=(const Polynomial& p1, const Polynomial& p2);
    friend Polynomial operator+(const Polynomial& p1, const Polynomial& p2);
    friend Polynomial operator+(const Polynomial& p1);
    friend Polynomial operator-(const Polynomial& p1, const Polynomial& p2);
    friend Polynomial operator-(const Polynomial& p1);
    friend Polynomial operator*(const Polynomial& p1, const Polynomial& p2);
    friend Polynomial operator/(const Polynomial& p1, const Polynomial& p2);
    friend Polynomial operator%(const Polynomial& p1, const Polynomial& p2);

    Polynomial& operator+=(const Polynomial& p);
    Polynomial& operator-=(const Polynomial& p);
    Polynomial& operator/=(const Polynomial& p);
    Polynomial& operator*=(const Polynomial& p);
    Polynomial& operator%=(const Polynomial& p);

    explicit operator std::string() const;

    friend std::ostream& operator<<(std::ostream& out, const Polynomial& poly);
};

#endif // POLYNOMIAL_H
