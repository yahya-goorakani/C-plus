#include <iostream>
#include <chrono>
#include <thread>

int main() {
    int progress = 0;
    while (progress <= 100) {
        std::cout << "Progress: " << progress << "%" << std::endl;
        progress += 10;
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Задержка в 0.5 секунды
    }
    std::cout << "Process completed!" << std::endl;
    return 0;
}





#include<iostream>

int main(){
        int a ,b;

        std::cout << "...%" << std:: endl;

        for(a=5; a<=100; a+=5) {
                for(b=0; b<500000000; ++b);
                std::cout << "...%" << a << std:: endl;
        }
        std::cout << std::endl;
        return 0;
}