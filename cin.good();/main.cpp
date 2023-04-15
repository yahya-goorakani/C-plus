#include<iostream>




int main() {

        double x=0.0, y=0.0;
std::setlocale(LC_ALL, "russian_russuia.1225");

std::cout<< "Enter a first number:";
std::cin>> x;

std::cout<< "Enter a second number:";
std::cin>> y;

if(!std::cin.good() ){  
        std::cout<< "\nОщебка при вводе числа!" <<std::endl;
        std::cin.clear();
        std::cin.ignore(200, '\n').get();
        std::exit(1);
}

else if(y==0.0) {
        std::cout<< "На нуль делить нельзя!" <<std::endl;
        std::cin.ignore(200, '\n').get();
        std::exit(1);
}

std::cout<< "x / y = " << x/y <<std::endl;
std::cin.ignore(200, '\n');//.get();
return 0;
}    
