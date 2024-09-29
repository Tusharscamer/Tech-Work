// non const object can access const operator non member function
#include<iostream>
using namespace std;
class Complex{
    public:
     int real;
     int img;
};
Complex operator+(Complex num1,Complex num2)const{
        Complex num3;
        num3.real=num1.real+num2.real;
        num3.img=num1.img+num2.img;
        return num3;
}
int main(){
     Complex num1;
     Complex num2;
     num1.real=6;
     num2.real=4;
     num1.img=4;
     num2.img=4;
     Complex num3;
     num3=num1+num2;
     cout<<"ans is "<<endl;
     cout<<num3.real<<endl;
     cout<<num3.img<<endl;
}