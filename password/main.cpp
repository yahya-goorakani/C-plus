#include<iostream>
#include<cstring>
#include"conio.h"
int main() {
        char choose[17], cha;
        int i=0;
        int l=0;
        char password[17], ch;
        bool flag=false;
        std::cout<< "Choose a password:max " <<std::endl;
        //std::cin>> choose;
        do{ 
                cha=getch();
                if(l>15 || cha == '\t' || cha == '\n') {
                        flag=true;
                        choose[l] = '\0';
                }

 else if( (cha>47 && cha<58) || (cha>64 && cha<91) || (cha>96 && cha<123) ) {
                        choose[l]=cha;
                        std::cout<< '*';
                        ++l;
                }
                else{
                        std::cout<<std::endl<< "Error1" <<std::endl;
                        return 0;
                }
                }while(!flag);

        std::cout<<std::endl<< "Enter your pasword:" <<std::endl;
        do {
                ch=getch();
                if(i>15 || ch=='\t' || ch=='\n') {
                        flag=false;
                        password[i]= '\0';
                }

        else if( (ch>47 && ch<58) || (ch>64 && ch<91) || (ch>96 && ch<123) ) {
                password[i] = ch;
                std::cout<< "*";
                ++i;
        }
                else{ 
                        std::cout<<std::endl<< "ERROR2" <<std::endl;
                        return 0;
                }
        }while(flag);
        if(std::strcmp(password,choose)==0){
                std::cout<<std::endl<< "Ok" <<std::endl;
        }
        else{
                std::cout<<std::endl<< "ERROR3"<<std::endl;
        }
        return 0;
        }
*/


/*
#include<iostream>
#include"conio.h"
int main(int argc, char *argv[]) {

        std::cout<< "argc=" << argc <<std::endl;

        for(int i=0; i<argc; ++i) {
                std::cout<< argv[i] <<std::endl;
                getch();
                }
        return 0;
}