#include <iostream>
#include <string>
#include <initializer_list>
#include <sstream>
#include <cmath>
class Polynomial {
public:
    // Constructors and destructor
    Polynomial(); //Default Constructor
    Polynomial(const Polynomial& other); // Copy Constructor
    Polynomial(Polynomial&& other) noexcept; // Move Constructor
    Polynomial(double* coeffs, int degree); // a constructor that accepts C arrays
    Polynomial(std::initializer_list<double> coeffs); //  a constructor with an initialization list
    ~Polynomial(); // destructor

    // Calculation method
    double calculate(double x) const; // a calculation method for a given X

    // Accessors
    double operator[](int index) const; // [] overload
    double& operator[](int index); // [] overload
    double at(int index) const; // at method

    // Arithmetic operators
    Polynomial operator+() const; // overloading of +
    Polynomial operator-() const; // overloading of -
    Polynomial operator+(const Polynomial& other) const; // overloading of +
    Polynomial operator-(const Polynomial& other) const; // overloading of -
    Polynomial operator*(const Polynomial& other) const; // overloading of *
    Polynomial operator*(double scalar) const; // overloading of *
    Polynomial& operator+=(const Polynomial& other); // overloading of + with replace
    Polynomial& operator-=(const Polynomial& other); // overloading of - with replace
    Polynomial& operator*=(const Polynomial& other); // overloading of * with replace
    Polynomial& operator*=(double scalar); // overloading of * with replace

    // Comparison operators
    bool operator==(const Polynomial& other) const; // overloading of ==
    bool operator!=(const Polynomial& other) const; // overloading of !=

    // Assignment operators
    Polynomial& operator=(const Polynomial& other); // overloading of assignment
    Polynomial& operator=(Polynomial&& other) noexcept; // overloading of assignment

    // Friend function for output
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly); // overloading of output print

    // Type casting operator to string
    operator std::string() const; // overloading of string

private:
    double* m_coeffs;
    int m_degree;
};

// Default constructor
Polynomial::Polynomial()
    : m_coeffs(nullptr), m_degree(0)
{
}

// Copy constructor
Polynomial::Polynomial(const Polynomial& other)
    : m_coeffs(nullptr), m_degree(other.m_degree)
{
    m_coeffs = new double[m_degree + 1];
    for (int i = 0; i <= m_degree; i++) {
        m_coeffs[i] = other.m_coeffs[i];
    }
}

// Move constructor
Polynomial::Polynomial(Polynomial&& other) noexcept
    : m_coeffs(other.m_coeffs), m_degree(other.m_degree)
{
    other.m_coeffs = nullptr;
    other.m_degree = 0;
}

// Constructor with C array
Polynomial::Polynomial(double* coeffs, int degree)
    : m_coeffs(nullptr), m_degree(degree)
{
    m_coeffs = new double[m_degree + 1];
    for (int i{}; i <= m_degree; i++) {
        m_coeffs[i] = coeffs[i];
    }
}

// Constructor with initialization list
Polynomial::Polynomial(std::initializer_list<double> coeffs)
    : m_coeffs(nullptr), m_degree(coeffs.size() - 1)
{
    m_coeffs = new double[m_degree + 1];
    int i{};
    std::initializer_list<double>::iterator it;
    for(it = coeffs.end(); it != coeffs.begin(); --it){
        m_coeffs[i] = *it;
        i++;
    }
//    for (float coeff : coeffs) {
//        m_coeffs[i] = coeff;
//        i++;
//    }
}

// Destructor
Polynomial::~Polynomial()
{
    delete[] m_coeffs;
}

// Calculation method
double Polynomial::calculate(double x) const
{
    double result = 0.0;
    for (int i = 0; i <= m_degree; i++) {
        result += m_coeffs[i] * pow(x, i);
    }
    return result;
}

// Accessors
double Polynomial::operator[](int index) const
{
    return m_coeffs[index];
}

double& Polynomial::operator[](int index)
{
    return m_coeffs[index];
}

double Polynomial::at(int index) const
{
    if (index < 0 || index > m_degree) {
        throw std::out_of_range("Index out of range");
    }
    return m_coeffs[index];
}

// Aithmetic operators
Polynomial Polynomial::operator+() const
{
    return *this;
}

Polynomial Polynomial::operator-() const
{
    Polynomial result(*this);
    for (int i = 0; i <= m_degree; i++) {
        result[i] = -result[i];
    }
    return result;
}

Polynomial Polynomial::operator+(const Polynomial& other) const
{
    int maxDegree = std::max(m_degree, other.m_degree);
    Polynomial result;
    result.m_coeffs = new double[maxDegree + 1];
    result.m_degree = maxDegree;
    for (int i = 0; i <= maxDegree; i++) {
        double coeff1 = (i <= m_degree) ? m_coeffs[i] : 0.0;
        double coeff2 = (i <= other.m_degree) ? other.m_coeffs[i] : 0.0;
        result[i] = coeff1 + coeff2;
    }
    return result;
}

Polynomial Polynomial::operator-(const Polynomial& other) const
{
    return *this + (-other);
}

Polynomial Polynomial::operator*(const Polynomial& other) const
{
    Polynomial result;
    result.m_coeffs = new double[m_degree + other.m_degree + 1];
    result.m_degree = m_degree + other.m_degree;
    for (int i = 0; i <= result.m_degree; i++) {
        result[i] = 0.0;
        for (int j = 0; j <= i; j++) {
            if (j <= m_degree && i - j <= other.m_degree) {
                result[i] += m_coeffs[j] * other[i - j];
            }
        }
    }
    return result;
}

Polynomial Polynomial::operator*(double scalar) const
{
    Polynomial result(*this);
    for (int i = 0; i <= m_degree; i++) {
        result[i] *= scalar;
    }
    return result;
}

Polynomial& Polynomial::operator+=(const Polynomial& other)
{
    *this = *this + other;
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& other)
{
    *this = *this - other;
    return *this;
}

Polynomial& Polynomial::operator*=(const Polynomial& other)
{
    *this = *this * other;
    return *this;
}

Polynomial& Polynomial::operator*=(double scalar)
{
    *this = *this * scalar;
    return *this;
}

// Comparison operators
bool Polynomial::operator==(const Polynomial& other) const
{
    if (m_degree != other.m_degree) {
        return false;
    }
    for (int i = 0; i <= m_degree; i++) {
        if (m_coeffs[i] != other.m_coeffs[i]) {
            return false;
        }
    }
    return true;
}

bool Polynomial::operator!=(const Polynomial& other) const
{
    return !(*this == other);
}

// Assignment operators
Polynomial& Polynomial::operator=(const Polynomial& other)
{
    if (this != &other) {
        delete[] m_coeffs;
        m_coeffs = new double[other.m_degree + 1];
        m_degree = other.m_degree;
        for (int i = 0; i <= m_degree; i++) {
            m_coeffs[i] = other.m_coeffs[i];
        }
    }
    return *this;
}

Polynomial& Polynomial::operator=(Polynomial&& other) noexcept
{
    if (this != &other) {
        delete[] m_coeffs;
        m_coeffs = other.m_coeffs;
        m_degree = other.m_degree;
        other.m_coeffs = nullptr;
        other.m_degree = 0;
    }
    return *this;
}
// Friend function for output
std::ostream& operator<<(std::ostream& os, const Polynomial& poly)
{
bool firstTerm = true;
for (int i = poly.m_degree; i >= 0; i--) {
double coeff = poly[i];
if (coeff != 0.0) {
if (!firstTerm) {
os << ((coeff > 0.0) ? " + " : " - ");
} else {
firstTerm = false;
if (coeff < 0.0) {
os << "-";
}
}
    coeff = std::abs(coeff);
    if (i == 0 || coeff != 1.0) {
        os << coeff;
        }
        if (i > 0) {
            os << "x";
        if (i > 1) {
            os << "^" << i;
        }
        }
        }
        }
        if (firstTerm) {
        os << "0";
        }
    return os;
    }

// Type casting operator to string
Polynomial::operator std::string() const
{
std::stringstream ss;
ss << *this;
return ss.str();
}


int main(){
    double coeffs[] = {-3, 0, 1, 2};
    Polynomial p1(coeffs, 3);
    
    double result = p1.calculate(2.0);
    std::cout << "p1(2) = " << result << std::endl;
}