#include<iostream>


namespace H {
        int h=11;
        void print() {
                std::cout<< h <<std::endl;
}
}
namespace H {
        int n = 12;
        namespace H1{
                int j = 13;
        }
}

int main() {
//using H::H1::j;
//using namespace H;
//using namespace H1;
        H::print();
        std::cout<< H::h <<std::endl;
        std::cout<< H::n <<std::endl << H::H1::j <<std::endl;
        return 0;
}


