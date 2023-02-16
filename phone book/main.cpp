#include<iostream>
#include<fstream>

using namespace std;


int main(){


int a;
cout<<"Enter '0' to search the phone number list and enter '1' to add a phone number:";
cin>>a;

        if(a==0){
        ifstream phone_file("phone.txt", std::ios_base::app);
        long number;
        string name,search_name;
        bool found=false;

        cout<<"Enter a name for finding its phone number:";
        cin>>search_name;
        cout<<endl;

                while(phone_file>>number){
                phone_file>>name;
                if(name==search_name){
                        cout<<name<<":"<<number<<endl;
                        found=true;
                        break;
                if(found==false)
                        cout<<search_name<<"is not in this phonebook"<<endl;
                }
        }
        }
        if(a==1){
        ofstream phone_file("phone.txt", std::ios_base::app);
        long number;
        string name,search_name;
        cout<<"Enter a number for each name (0 for)"<<endl;
        for(; ;){

         cout<<"number:";
         cin>>number;
         if(number==0) break;
         phone_file<<number<<' ';
         cout<<"Name:";
         cin>>name;
         phone_file<<name<<' ';
         cout<<endl;
        }

        }
}

