#include<iostream>

int main() {

        int arr[4][5] ={ {1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5} };
                                        
        for(int i=0; i<4; ++i) {
                for(int j=0; j<5; ++j) {

        std::cout<< "arr" << "[" << i << "]" << "[" << j << "]" << ":" << arr[i][j] <<std::endl;
                }  
        }
        return 0;
}
