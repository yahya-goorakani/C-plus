#include<iostream>
#include<typeinfo>

int main() {
        long int a = 1;
        double s = 2.2;
        int d = 3;

std::cout<< typeid(a).name() <<std::endl;
std::cout<< typeid(s).name() <<std::endl;
std::cout<< typeid(d).name() <<std::endl;
std::cout<< typeid(12.1f).name() <<std::endl;
if(typeid(a) == typeid(d) ) {
        std::cout<< "==" <<std::endl;
}
else {
        std::cout<< "!=" <<std::endl;
}
if(typeid(s) != typeid(d) ) {
        std::cout<< "!=" <<std::endl;
}
else {
        std::cout<< "==" <<std::endl;
}

return 0;
}
