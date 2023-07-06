#include "class.hpp"

//operator+=: Добавляет другую дробь к текущей дроби и возвращает ссылку на текущий объект. Обновляет числитель и знаменатель, а затем нормализует дробь.
Fraction& Fraction::operator+=(const Fraction& other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator *= other.denominator;
    normalize();
    return *this;
}

//operator-=: Вычитает другую дробь из текущей дроби и возвращает ссылку на текущий объект. Обновляет числитель и знаменатель, а затем нормализует дробь.
Fraction& Fraction::operator-=(const Fraction& other) {
    numerator = numerator * other.denominator - other.numerator * denominator;
    denominator *= other.denominator;
    normalize(); return *this;
}

//operator*=: Умножает текущую дробь на другую дробь и возвращает ссылку на текущий объект. Обновляет числитель и знаменатель, а затем нормализует дробь.
Fraction& Fraction::operator*=(const Fraction& other) {
    numerator *= other.numerator;
    denominator *= other.denominator;
    normalize();
    return *this;
}

//operator/=: Делит текущую дробь на другую дробь и возвращает ссылку на текущий объект. Обновляет числитель и знаменатель, а затем нормализует дробь.
Fraction& Fraction::operator/=(const Fraction& other) {
    numerator *= other.denominator;
    denominator *= other.numerator;
    normalize();
    return *this;
}

//operator= (копирующий оператор присваивания): Присваивает значения числителя и знаменателя другой дроби текущей дроби и возвращает ссылку на текущий объект.
Fraction& Fraction::operator=(const Fraction& other) {
    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}

//operator=(Fraction&& other) noexcept: Перемещающий оператор присваивания. Присваивает значения числителя и знаменателя другой дроби текущей дроби, используя std::exchange, и возвращает ссылку на текущий объект. Это позволяет оптимизировать процесс присваивания при работе с временными объектами.
Fraction& Fraction::operator=(Fraction&& other) noexcept {
    numerator = std::exchange(other.numerator, 0);
    denominator = std::exchange(other.denominator, 1);
    return *this;
}

//normalize: Нормализует текущую дробь, сокращая ее на наибольший общий делитель числителя и знаменателя. Если знаменатель равен нулю, выбрасывается исключение std::invalid_argument. Если числитель равен нулю, знаменатель устанавливается равным 1.
void Fraction::normalize() {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    if (numerator == 0) {
        denominator = 1;
    } else {
        int sign = (numerator > 0 ? 1 : -1) * (denominator > 0 ? 1 : -1);
        int g = gcd(abs(numerator), abs(denominator));
        numerator = sign * abs(numerator) / g;
        denominator = abs(denominator) / g;
    }
}

//operator<<: Оператор вывода для класса Fraction. Выводит дробь в формате "числитель/знаменатель" или просто "числитель", если знаменатель равен 1
std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    if (fraction.denominator == 1) {
        os << fraction.numerator;
    } else {
        os << fraction.numerator << '/' << fraction.denominator;
    }
    return os;
}

//operator>>: Оператор ввода для класса Fraction. Считывает дробь в формате "числитель/знаменатель" или просто "числитель", если знаменатель равен 1.
std::istream& operator>>(std::istream& is, Fraction& fraction) {
    int num, den = 1;
    char slash;
    is >> num;
    if (is.peek() == '/') {
        is >> slash >> den;
    }
    fraction = Fraction(num, den);
    return is;
}

//operator std::string() const: Оператор преобразования в строку. Возвращает строковое представление дроби в формате "числитель/знаменатель" или просто "числитель", если знаменатель равен 1.
Fraction::operator std::string() const {
    if (denominator == 1) {
        return std::to_string(numerator);
    } else {
        return std::to_string(numerator) + '/' + std::to_string(denominator);
    }
}

//operator""_f(long double value): Пользовательский литерал для создания объекта Fraction из числа с плавающей точкой.
// User-defined literals
Fraction operator""_f(long double value) { return Fraction(static_cast<double>(value)); }
//operator""_f(unsigned long long value): Пользовательский литерал для создания объекта Fraction из целого числа.
Fraction operator""_f(unsigned long long value) { return Fraction(static_cast<int>(value), 1); }

//test_input_output: проверяет операторы ввода и вывода (>> и <<) для класса Fraction.
void test_input_output() {
    Fraction f1, f2, f3;
    std::cout << "Enter three fractions: "<<std::endl;
    std::cin >> f1 >> f2 >> f3;
    std::cout << "You entered: " << f1 << ' ' << f2 << ' ' << f3 << '\n';
     std::cout << std::endl;
}


// test_constructors: проверяет конструктор по умолчанию, параметризованный конструктор, конструктор копирования и конструктор перемещения.
void test_constructors() {

Fraction f1;
    Fraction f2(3, 4);
    Fraction f3(-2, 5);
    Fraction f4(2.5);
    Fraction f5(f2);
    Fraction f6(std::move(f3));
    Fraction f0;
    std::cout <<"test constructors:" << f1 << ' ' << f2 << ' ' << f3 << ' ' << f4 << ' ' << f5 << ' ' << f6 << '\n';
     std::cout << std::endl;
}

//test_arithmetic_operators: проверяет арифметические операторы (+, -, *, /) и их составные версии присваивания (+=, -=, *=, /=) для класса Fraction.
void test_arithmetic_operators() {
    Fraction f1(1, 2), f2(3, 4), f3(-2, 5), f4(2.5), f0;
    std::cout << "test arithmetic operators : " << std::endl;
    std::cout << f1 <<" + " << f2 << " = " << f1 + f2 << std::endl << f1 << " - " << f2 << " = " << f1 - f2 << std::endl << f1 << " * " << f2 << " = " << f1 * f2 << std::endl << f1 << " / " << f2 << " = " << f1 / f2 << '\n' << std::endl;

    std::cout << -f1 << ' ' << +f2 << std::endl << '\n'; 

f0=f1+f2;
    std::cout << f1 << " + " << f2 << " = " << f0 << std::endl;
f0=f2-f3;
    std::cout << f2 << " - " << f3 << " = " <<  f0 << std::endl;
f0=f3*f4;
    std::cout << f3 << " * " << f4 << " = " << f0 << std::endl; 
f0=f4/f1;
    std::cout << f4 << " / " << f1 << " = " << f0 << std::endl;
    std::cout << std::endl;
    f1 += f2;
    f2 -= f3;
    f3 *= f4;
    f4 /= f1;   //ощибка
    std::cout << f1 << ' ' << f2 << ' ' << f3 << ' ' << f4 << '\n';
     std::cout << std::endl;
}

//test_comparison_operators: проверяет операторы сравнения (==, !=, <, <=, >, >=) для класса Fraction.

void test_comparison_operators() {
    Fraction f1(1, 2), f2(3, 4), f3(-2, 5), f4(2.5), f5(1);
    
    std::cout << std::boolalpha << f2 << " == " << f3 << " = " <<(f2 == f3) << std::endl << f2 << " != " << f3 << " = " << (f2 != f3) << std::endl << f2 << " < " << f3 << " = " << (f2 < f3) << std::endl << f2 << " <= " << f3 << " = " << (f2 <= f3) << std::endl << f2 << " > " << f3 << " = " << (f2 > f3) << std::endl << f2 << " >= " << f3 << " = " << (f2 >= f3) << '\n';

        std::cout << std::boolalpha << f3 << " == " << f4 << " = " <<(f3 == f4) << std::endl << f3 << " != " << f4 << " = " << (f3 != f4) << std::endl << f3 << " < " << f4 << " = " << (f3 < f4) << std::endl << f3 << " <= " << f4 << " = " << (f3 <= f4) << std::endl << f3 << " > " << f4 << " = " << (f3 > f4) << std::endl << f3 << " >= " << f4 << " = " << (f3 >= f4) << '\n';
        std::cout << std::endl;
}




void compare_integer_fraction() {
Fraction f1(1, 2), f2(6, 4), f3(4, 3), f4(5, 8);
std::cout << std::boolalpha << (1<f1) <<std::endl;
std::cout << std::boolalpha << (f1<1) <<std::endl;
std::cout <<std::endl;
std::cout << std::boolalpha << (6>f2) <<std::endl;
std::cout << std::boolalpha << (f2>6) <<std::endl;                                              
std::cout <<std::endl;
std::cout << std::boolalpha << (9<=f3) <<std::endl;
std::cout << std::boolalpha << (f3<=9) <<std::endl;
std::cout <<std::endl;
std::cout << std::boolalpha << (2>=f4) <<std::endl;
std::cout << std::boolalpha << (f4>=2) <<std::endl;
std::cout <<std::endl;
}

//test_assignment_operators: проверяет операторы присваивания (=) для класса Fraction.
void test_assignment_operators() {
    Fraction f1(1, 2), f2(3, 4), f3(-2, 5), f4(2.5);
    f1 = f2;
    f2 = f3;
    f3 = f4;
    std::cout << "test assignment operators : " << std::endl;
    std::cout << f1 << ' ' << f2 << ' ' << f3 << '\n';
    std::cout << std::endl;
}

//test_type_casting: проверяет операторы приведения типов (float, double, std::string) для класса Fraction.
void test_type_casting() {
    Fraction f1(1, 2), f2(3, 4), f3(-2, 5), f4(2.5);
    std::cout << "checks cast operators : " << std::endl;
    std::cout << f1 << " == " << static_cast<float>(f1) << std::endl << f2 << " == " << static_cast<double>(f2) << std::endl<< f3 << " == " << static_cast<std::string>(f3) << '\n';
    std::cout << std::endl;
}

//test_user_defined_literals: проверяет определяемые пользователем литералы для класса Fraction.
void test_user_defined_literals() {
    Fraction f1 = 2_f / 4_f;
    Fraction f2 = 3_f / 4_f ;
    Fraction f3 = 2_f / 5_f * 3_f;
    std::cout << " 2 / 4 = " << f1 << std::endl << " 3 / 4 = " << f2 << std::endl << " 2 / 5 * 3 " << f3 << std::endl;
}
