#include<iostream>

void func();

int main() {
        func();
        func();
        func();

        std::cin.get();
        return 0;
}
void func() {
        static int x = 0;
        ++x;
        std::cout<< "x = "<< x <<std::endl;
}