#ifndef LABA_1_CLASS_HPP
#define LABA_1_CLASS_HPP 
#include <iostream>
#include <cmath>
#include <utility>
#include <string>

class Fraction {
public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int num, int den) : numerator(num), denominator(den) { normalize(); }
    Fraction(double value) : numerator(round(value * 100)), denominator(100) { normalize(); }
    Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {}
    Fraction(Fraction&& other) noexcept : numerator(std::exchange(other.numerator, 0)), denominator(std::exchange(other.denominator, 1)) {}

    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& is, Fraction& fraction);

    Fraction operator+() const { return *this; }
    Fraction operator-() const { return Fraction(-numerator, denominator); }

    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);

    friend Fraction operator+(Fraction left, const Fraction& right) { return left += right; }
    friend Fraction operator-(Fraction left, const Fraction& right) { return left -= right; }
    friend Fraction operator*(Fraction left, const Fraction& right) { return left *= right; }
    friend Fraction operator/(Fraction left, const Fraction& right) { return left /= right; }
    friend bool operator<(int left, const Fraction& right) { return Fraction(left, 1) < right; }
    friend bool operator>(int left, const Fraction& right) { return Fraction(left, 1) > right; }
    friend bool operator<=(int left, const Fraction& right) { return Fraction(left, 1) <= right; }
    friend bool operator>=(int left, const Fraction& right) { return Fraction(left, 1) >= right; }

    template <typename T>
    bool operator==(const T& other) const {
        if constexpr (std::is_integral_v<T>) {
            return numerator == other * denominator;
        } else {
            return numerator == other.numerator && denominator == other.denominator;
        }
    }

    template <typename T>
    bool operator!=(const T& other) const {
        return !(*this == other);
    }

    template <typename T>
    bool operator<(const T& other) const {
        if constexpr (std::is_integral_v<T>) {
            return numerator < other * denominator;
        } else {
            return numerator * other.denominator < other.numerator * denominator;
        }
    }

    template <typename T>
    bool operator<=(const T& other) const {
        return *this < other || *this == other;
    }

    template <typename T>
    bool operator>(const T& other) const {
        return !(*this <= other);
    }

    template <typename T>
    bool operator>=(const T& other) const {
        return !(*this < other);
    }

    Fraction& operator=(const Fraction& other);
    Fraction& operator=(Fraction&& other) noexcept;

    operator float() const { return static_cast<float>(numerator) / denominator; }
    operator double() const { return static_cast<double>(numerator) / denominator; }
    operator std::string() const;

    ~Fraction() = default;

private:
    int numerator;
    int denominator;
    void normalize();
    int gcd(int a, int b) const { return b == 0 ? a : gcd(b, a % b); }
};

#endif