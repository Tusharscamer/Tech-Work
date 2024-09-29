#include<iostream>
using namespace std;
class Complex{
    public:
     int real;
     int img;
};
Complex operator+(Complex num1,int num2){
        Complex num3;
        num3.real=num1.real+num2;
        num3.img=num1.img+num2;
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
     int num4=3;
     num3=num1+num4;
     cout<<"ans is "<<endl;
     cout<<num3.real<<endl;
     cout<<num3.img<<endl;
}