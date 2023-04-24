include<iostream>

int main(){
        const short YA = 1;
        const short SIZE = 3;
        int i=0, *p=0, arrA[SIZE]={10,30, 20}, arrB[YA]={50}, *y=0;
        
        p=arrA;
        y=arrB;
for(i=0; i<SIZE+YA; ++i){

if(i<=SIZE-1) {
        std::cout<< "arrA["<< i << "]:" <<  *p++ <<std::endl;
}
else{
        std::cout<< "ArrB[" << i-SIZE << "]:" << *y++ <<std::endl;
        }
}

std::cout<<"______________________"<<std::endl;



p=&arrA[SIZE-1];
std::cout<< "Return the values of array elements in reverse order:arrA=" <<std::endl;
for(i=SIZE-1; i>=0; --i) {
        std::cout<< *p-- <<std::endl;
}
std::cout<<"_______________________"<<std::endl;




p=&arrA[0];
std::cout<< "multiplication:(arrA*2)=" <<std::endl;
for(i=0; i<SIZE; ++i) {
        std::cout<< (*p++)*2 <<std::endl;
}
std::cout<<"________________________"<<std::endl;


std::cout<< "Return the values of the array elements in reverse and multiplied by 3:(arrA*3)" <<std::endl; 
p=&arrA[SIZE-1];
for(i=SIZE-1; i>=0; --i) {
        std::cout<< (*p--)*3 <<std::endl;
}
std::cout<<"___________________"<<std::endl;


p=&arrA[0];
y=&arrB[0];
int q=0;

for(i=0; i<SIZE; ++i) {
        if(SIZE==YA ) {
                q+=(*p++) * (*y++) ;
        }
        if( SIZE==1 ) {
                q+=(*p) * (*y++) ;
        }
        if( YA==1 ) {
                q+=(*p++) * ( *y );
        }  

        else{
                std::cout<< "Erorr!the number of elements is not equal." <<std::endl;
                break;
        }
}
std::cout<< "multiplication:(arrA*arrB)=" << q <<std::endl;
   
std::cout<<"_________________"<<std::endl;

  
p=arrA;
y=arrB;
std::cout<< "subtraction:(arrA-arrB):" <<std::endl;
for(i=0; i<YA+SIZE; ++i) {
if(YA==SIZE) {   
        if(i<=SIZE-1) {
        std::cout<< "arrA=[" << i << "]=" << (*p++) - (*y++) <<std::endl;
        }
        else if(i==SIZE) {
                p=arrA;
                y=arrB;
                std::cout<< "sum:(arrA+arrB):" <<std::endl<<std::endl;}

        if(i>=SIZE) {
 
        std::cout<< "arrA=[" << i-SIZE << "]=" << (*p++) + (*y++) <<std::endl;
        }   
}
else{
        std::cout<< "Erorr!the number of elements is not equal."<<std::endl;
        break;
}
}
return 0;
}