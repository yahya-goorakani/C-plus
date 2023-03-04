#include<iostream>
#include<cmath>
#include<complex>

using namespace std;

class com{
        double reall,img;

public:
        void read()
        {

                cout<<"Real part value:";
                cin>>reall;
                cout<<"Img part value:";
                cin>>img;
        }
        void display();
                com operator+(com);
                com operator-(com);
                com operator*(com);
                com operator/(com);
                com operator~(void);

                com sin_value();
                com cos_value();
                com tan_value();

                com sinh_value();
                com cosh_value();
                com tanh_value();

                com log_value();
                com norm_value();
                com abs_value();
                com arg_value();
                com power_value();
                com exp_value();
                com sqrt_value();

                        double get_real()
                        {
                                return((*this).reall);
}
                        double get_img()
                        {
                                return((*this).img);
                        }
        };

        void com::display()
        {
                if(img>=0) cout<<reall<<"+i"<<img<<endl;
                else{
                        cout<<reall<<"-i"<<(-1)*img<<endl;
                }
        }





com com::operator+(com o2)
{
        com temp;
        temp.reall=reall+o2.reall;
        temp.img=img+o2.img;
        return temp;
}

com com::operator-(com o2)
{
        com temp;
        temp.reall=reall-o2.reall;
        temp.img=img-o2.img;
        return temp;
}

com com::operator*(com o2)
{
        com temp;
        temp.reall=(reall*o2.reall)+(-1*(img*o2.img));
        temp.img=(img*o2.reall)+(reall*o2.img);
        return temp;
}

com com::operator/(com o2)
{
        com o,num,den,temp;
        o=~o2;
        num=(*this)*(o);
        den=o2*o;
        temp.reall=num.reall/den.reall;
        temp.img=num.img/den.reall;
        return temp;

}

com com::operator~(void)
{
        com temp;
        temp.reall=reall;
        temp.img=-1*img;
        return temp;
}




com com::sin_value(void)
{

        com temp;
        complex<double> cn=((*this).reall,(*this).img);
        complex<double> sam;
        sam=sin(cn);
        temp.reall=real(sam);
        temp.img=imag(sam);
        return temp;
}

com com::cos_value(void)
{
        com temp;
        complex<double> cn=((*this).reall,(*this).img);
        complex<double> sam;
        sam=cos(cn);
        temp.reall=real(sam);
        temp.img=imag(sam);
        return temp;
}
 com com::tan_value(void)
{
        com temp;
        complex<double> cn=((*this).reall,(*this).img);
        complex<double> sam;
        sam=tan(cn);
        temp.reall=real(sam);
        temp.img=imag(sam);
        return temp;
}

com com::sinh_value(void)
{
        com temp;
        complex<double> cn=((*this).reall,(*this).img);
        complex<double> sam;
        sam=sinh(cn);
        temp.reall=real(sam);
        temp.img=imag(sam);
        return temp;
}

com com::cosh_value(void)
{
        com temp;
        complex<double> cn=((*this).reall,(*this).img);
        complex<double> sam;
        sam=cosh(cn);
        temp.reall=real(sam);
        temp.img=imag(sam);
        return temp;
}

com com::tanh_value(void)
{
        com temp;
        complex<double> cn=((*this).reall,(*this).img);
        complex<double> sam;
        sam=tanh(cn);
        temp.reall=real(sam);
        temp.img=imag(sam);
        return temp;
}
com com::log_value(void)
{
        com temp;
        complex<double> cn=((*this).reall,(*this).img);
        complex<double> sam;
        sam=log(cn);
        temp.reall=real(sam);
        temp.img=imag(sam);
        return temp;
}

com com::norm_value(void)
{
        com temp;
        complex<double> cn=((*this).reall,(*this).img);
        complex<double> sam;
        sam=norm(cn);
        temp.reall=real(sam);
        temp.img=imag(sam);
        return temp;
}
com com::abs_value(void){
        com temp;
        complex<double> cn=((*this).reall,(*this).img);
        complex<double> sam;
        sam=abs(cn);
        temp.reall=real(sam);
        temp.img=imag(sam);
        return temp;
}

com com::arg_value(void)
{
        com temp;
        complex<double> cn=((*this).reall,(*this).img);
        complex<double> sam;
        sam=arg(cn);
        temp.reall=real(sam);
        temp.img=imag(sam);
        return temp;
}

com com::power_value(void)
{
 int p;
        cout<<"Enter Power:";
        cin>>p;

        com temp;
        complex<double> cn=((*this).reall,(*this).img);
        complex<double> sam;
        sam=pow(cn,p);
        temp.reall=real(sam);
        temp.img=imag(sam);
        return temp;
}

com com::exp_value(void)
{
        com temp;
        complex<double> cn=((*this).reall,(*this).img);
        complex<double> sam;
        sam=exp(cn);
        temp.reall=real(sam);
        temp.img=imag(sam);
        return temp;
}

com com::sqrt_value(void)
{
        com temp;
        complex<double> cn=((*this).reall,(*this).img);
        complex<double> sam;
        sam=sqrt(cn);
        temp.reall=real(sam);
        temp.img=imag(sam);
        return temp;
}


int main()
{
        com o1,o2,o3;
        int choice;
        do{
                 cout << "\nEnter Choice\n\n";
                 cout << "1.Read Complex Number\n\n";
                           cout << "2.Display Complex Number\n\n";
                 cout << "3.Addition of Complex Number\n\n";
                 cout << "4.Subtraction of Complex Number\n\n";
                 cout << "5.Multiplication of Complex Number\n\n";
                 cout << "6.Division of Complex Number\n\n";
                 cout << "7.Conjugate of Complex Number\n\n";
                 cout << "8.Sine of Complex Number\n\n";
                 cout << "9.Cosine of Complex Number\n\n";
                 cout << "10.Tangent of Complex Number\n\n";
                 cout << "11.Sine Hyperbolic of Complex Number\n\n";
                 cout << "12.Cosine Hyperbolic of Complex Number\n\n";
                 cout << "13.Tangent Hyperbolic of Complex" "Number\n\n";
                 cout << "14.Natural Log of Complex Number\n\n";
                 cout << "15.Norm of Complex Number\n\n";
                 cout << "16.Absolute of Complex Number\n\n";
                 cout << "17.Argument of Complex Number\n\n";
                 cout << "18.Power of Complex Number\n\n";
                 cout << "19.Exponential of Complex Number\n\n";
                 cout << "20.Square Root of Complex Number\n\n";
                 cout << "21.Show Real Values of Complex Number\n\n";
                 cout << "22.Show Imaginary Values of Complex " "Number\n\n";
                 cout << "23.Exit\n\n";


                cin >> choice;
                cout << "\n";
switch(choice)
{
        case 1:
                cout<<"Enter Values:\n";
                o1.read();
                o2.read();
                break;

        case 2:
                cout<<"values are:\n";
                o1.display();
                o2.display();
                break;
        case 3:
                o3=o1+o2;
                cout<<"Addition is:\n";
              o3.display();
                break;
        case 4:
                o3=o1-o2;
                cout<<"Subtraction is:\n";
                o3.display();
                break;
        case 5:
                o3=o1*o2;
                cout<<"Multipliction is:\n";
                o3.display();
                break;
        case 6:
                o3=o1/o2;
                cout<<"Division is:\n";
                o3.display();
                break;
        case 7:
                cout<<"Conjugate is:\n";
                o3=~o1;
                o3.display();
                o3=~o2;
                o3.display();
                break;
        case 8:
                cout<<"Sin of 1st Complex Number is:\n";
                o3=o1.sin_value();
                o3.display();
                cout<<"Sin of 2nd Complex Number is:\n";
                o3=o2.sin_value();
                o3.display();
                break;
        case 9:
                cout<<"Cos of 1st Complex Number is:\n";
                o3=o1.cos_value();
                o3.display();
                cout<<"Cos of 2nd Complex Number is:\n";
                o3=o2.cos_value();
                  o3.display();
                break;
        case 10:
                cout<<"Tan of 1st Complex Number is:\n";
                o3=o1.tan_value();
                o3.display();
                cout<<"Tan of 2nd Complex Number is:\n";
                o3=o2.tan_value();
                o3.display();
                break;
        case 11:
                cout<<"Sinh of 1st Complex Number is:\n";
                o3=o1.sinh_value();
                o3.display();
                cout<<"Sinh of 2nd Complex Number is:\n";
                o3=o2.sinh_value();
                o3.display();
                break;
        case 12:
                cout<<"Cosh of 1st Complex Number is:\n ";
                o3=o1.cosh_value();
                o3.display();
                cout<<"Cosh of 2nd Complex Number is:\n";
                o3=o2.cosh_value();
                o3.display();
                break;
        case 13:
                cout<<"Tanh of 1st Complex Number is:\n";
                o3=o1.tanh_value();
                o3.display();
                cout<<"Tanh of 2nd Complex Number is:\n";
                o3=o2.tanh_value();
                o3.display();
                break;
        case 14:
              cout<<"Log of 1st Complex Number is:\n:";
                o3=o1.log_value();
                o3.display();
                cout<<"Log of 2nd Complex Number is:\n";
                o3=o2.log_value();
                o3.display();
                break;
        case 15:
                cout<<"Norm of 1st Complex Number is:\n";
                o3=o1.norm_value();
                o3.display();
                cout<<"Norm of 2nd complex Number is:\n";
                o3=o2.norm_value();
                o3.display();
                break;
        case 16:
                cout<<"Absolute of 1st Complex Number is:\n";
                o3=o1.abs_value();
                o3.display();
                cout<<"Absolute of 2nd Complex number is:\n";
                o3=o2.abs_value();
                o3.display();
                break;
        case 17:
                cout<<"Argument of 1st Complex Number is:\n";
                o3=o1.arg_value();
                o3.display();
                cout<<"Argument of 2nd Complex Number is:\n";
                o3=o2.arg_value();
                o3.display();
                break;
        case 18:
                cout<<"Power of 1st Complex Number is:\n";
                o3=o1.power_value();
          o3.display();
                cout<<"Power of 2nd Complex Number is:\n";
                o3=o1.power_value();
                o3.display();
                break;
        case 19:
                cout<<"Exponential of 1st Complex Number is:\n";
                o3=o1.exp_value();
                o3.display();
                cout<<"Exponential of 2nd Complex Number is:\n";
                o3=o2.exp_value();
                o3.display();
                break;
        case 20:
                cout<<"Square of 1st Complex Number is:\n";
                o3=o1.sqrt_value();
                o3.display();
                cout<<"Square of 2nd Complex Number is:\n";
                o3=o2.sqrt_value();
                o3.display();
                break;
        case 21:
                cout<<"Real Value of 1st Complex Number is:"<<o1.get_real()<<endl;
                cout<<"Real Value of 2nd Complex Number is:"<<o2.get_real()<<endl;
                break;
        case 22:
                cout<<"Imaginary Value of 1st Complex Number is:"<<o1.get_img()<<endl;
                cout<<"Imaginary Value of 2nd Complex Number is:"<<o2.get_img()<<endl;
                break;
        case 23:
                return 1;
                break;
        default:
                cout<<"Enter valid option!!";
        break;
}
}while(1);

        return 0;
}
                                                           
                                  