#include<iostream>


int main() {

        int x = 0, y = 0;
        bool flag = false;

        do { 
                std::cout << "x=";
                std::cin >> x;
                if(!std::cin.good() ) {
                        std::cout << std::endl <<"Error" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(225, '\n');
                }
        else flag = true;
        }while(!flag);
        flag=false;
        do {
                std::cout << "y=";
                std::cin >> y;
                if(!std::cin.good() ) {
                        std::cout << std::endl <<"Error" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(225, '\n');
                }       
        else flag = true;
        }while(!flag);
        std::cout << "Summa =" << x+y <<std::endl;
        return 0;
