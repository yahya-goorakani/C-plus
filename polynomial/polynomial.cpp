#include "polynomial.h"
#include <algorithm>
#include <sstream>

Polynomial::Polynomial() {
    degree = 0;
    coefficients = new double[1];
    coefficients[0] = 0;
}

Polynomial::Polynomial(const Polynomial& other) {
    degree = other.degree;
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; i++) {
        coefficients[i] = other.coefficients[i];
    }
}

Polynomial::Polynomial(Polynomial&& other) {
    degree = other.degree;
    coefficients = other.coefficients;
    other.degree = 0;
    other.coefficients = new double[1];
    other.coefficients[0] = 0;
}

Polynomial::Polynomial(double* coeffs, int deg) {
    degree = deg;
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; i++) {
        coefficients[i] = coeffs[i];
    }
}

Polynomial::Polynomial(float* coeffs, int deg) {
    degree = deg;
    coefficients = new double[degree + 1];
    for (int i = 0; i <= degree; i++) {
        coefficients[i] = static_cast<double>(coeffs[i]);
    }
}

Polynomial::Polynomial(std::initializer_list<double> coeffs) {
    degree = coeffs.size() - 1;
    coefficients = new double[degree + 1];
    std::copy(coeffs.begin(), coeffs.end(), coefficients);
}

Polynomial::~Polynomial() {
    delete[] coefficients;
}

double Polynomial::evaluate(double x) const {
    double result = 0;
    for (int i = degree; i >= 0; i--) {
        result += coefficients[i] * std::pow(x, i);
    }
    return result;
}

double& Polynomial::operator[](int i) {
    if (i < 0) {
        return coefficients[0];
    }
    if (i > degree) {
        double* tmp = new double[i + 1];
        std::copy(coefficients, coefficients + degree + 1, tmp);
        std::fill(tmp + degree + 1, tmp + i + 1, 0);
        degree = i;
        delete[] coefficients;
        coefficients = tmp;
    }
    return coefficients[i];
}

double Polynomial::operator[](int i) const {
    return coefficients[i];
}

double Polynomial::at(int i) const {
    if (i < 0 || i > degree) {
        throw std::out_of_range("Index out of range");
    }
    return coefficients[i];
}

Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        delete[] coefficients;
        degree = other.degree;
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coefficients[i] = other.coefficients[i];
        }
    }
    return *this;
}

Polynomial& Polynomial::operator=(Polynomial&& poly) {
    if (this != &poly) {
        delete[] coefficients;
        degree = poly.degree;
        coefficients = poly.coefficients;
        poly.degree = 0;
        poly.coefficients = new double[1];
        poly.coefficients[0] = 0;
    }
    return *this;
}

bool operator==(const Polynomial& p1, const Polynomial& p2) {
    if (p1.degree != p2.degree) {
        return false;
    }
    for (int i = 0; i <= p1.degree; i++) {
        if (p1.coefficients[i] != p2.coefficients[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const Polynomial& p1, const Polynomial& p2) {
    return !(p1 == p2);
}

Polynomial operator+(const Polynomial& p1, const Polynomial& p2) {
    Polynomial result;
    if (p1.degree > p2.degree) {
        result = p1;
        for (int i = 0; i <= p2.degree; i++) {
            result.coefficients[i] += p2.coefficients[i];
        }
    } else {
        result = p2;
        for (int i = 0; i <= p1.degree; i++) {
            result.coefficients[i] += p1.coefficients[i];
        }
    }
    return result;
}

Polynomial operator+(const Polynomial& p1) {
    return p1;
}

Polynomial operator-(const Polynomial& p1) {
    Polynomial result(p1);
    for (int i = 0; i <= result.degree; i++) {
        result.coefficients[i] *= -1;
    }
    return result;
}

Polynomial operator-(const Polynomial& p1, const Polynomial& p2) {
    Polynomial result;
    if (p1.degree > p2.degree) {
        result = p1;
        for (int i = 0; i <= p2.degree; i++) {
            result.coefficients[i] -= p2.coefficients[i];
        }
    } else {
        result = p2;
        for (int i = 0; i <= p1.degree; i++) {
            result.coefficients[i] = p1.coefficients[i] - result.coefficients[i];
        }
        for (int i = p1.degree + 1; i <= result.degree; i++) {
            result.coefficients[i] *= -1;
        }
    }
    return result;
}

Polynomial operator*(const Polynomial& p1, const Polynomial& p2) {
    int maxDegree = p1.degree + p2.degree;
    Polynomial result;
    delete[] result.coefficients;
    result.degree = maxDegree;
    result.coefficients = new double[maxDegree + 1];
    std::fill(result.coefficients, result.coefficients + maxDegree + 1, 0);

    for (int i = 0; i <= p1.degree; i++) {
        for (int j = 0; j <= p2.degree; j++) {
            result.coefficients[i + j] += (p1.coefficients[i] * p2.coefficients[j]);
        }
    }
    return result;
}

Polynomial operator/(const Polynomial& p1, const Polynomial& p2) {
    if (p2.degree == -1 || p1.degree < p2.degree) {
        return Polynomial();
    }

    Polynomial quotient;
    delete[] quotient.coefficients;
    quotient.coefficients = new double[p1.degree - p2.degree + 1];
    quotient.degree = p1.degree - p2.degree;

    Polynomial tmp(p1);
    for (int i = quotient.degree; i >= 0; i--) {
        quotient.coefficients[i] = tmp.coefficients[i + p2.degree] / p2.coefficients[p2.degree];
        for (int j = 0; j <= p2.degree; j++) {
            tmp.coefficients[i + j] -= quotient.coefficients[i] * p2.coefficients[j];
        }
    }
    return quotient;
}

Polynomial operator%(const Polynomial& p1, const Polynomial& p2) {
    if (p2.degree == -1 || p1.degree < p2.degree) {
        return p1;
    }

    Polynomial remainder(p1);
    for (int i = remainder.degree - p2.degree; i >= 0; i--) {
        double coeff = remainder.coefficients[i + p2.degree] / p2.coefficients[p2.degree];
        for (int j = 0; j <= p2.degree; j++) {
            remainder.coefficients[i + j] -= coeff * p2.coefficients[j];
        }
    }

    remainder.degree = p2.degree - 1;
    while (remainder.degree >= 0 && remainder.coefficients[remainder.degree] == 0) {
        remainder.degree--;
    }

    return remainder;
}

Polynomial& Polynomial::operator+=(const Polynomial& p) {
    *this = *this + p;
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& p) {
    *this = *this - p;
    return *this;
}

Polynomial& Polynomial::operator/=(const Polynomial& p) {
    *this = *this / p;
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& p) {
    *this = *this * p;
    return *this;
}

Polynomial& Polynomial::operator%=(const Polynomial& p) {
    *this = *this % p;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& poly) {
    std::string myPolynomial = static_cast<std::string>(poly);
    out << myPolynomial;
    return out;
}

Polynomial::operator std::string() const {
    std::string result;
    std::ostringstream out(result);
    if (coefficients[0] != 0) out << coefficients[0] << "x^" << 0;
    for (int i = 1; i <= degree; i++) {
        if (coefficients[i] > 0) out << " + " << coefficients[i] << "x^" << i;
        else if (coefficients[i] < 0) out << " - " << -coefficients[i] << "x^" << i;
    }
    return out.str();
}
