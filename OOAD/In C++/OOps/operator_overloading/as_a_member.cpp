#include<iostream>
using namespace std;
class Complex{
    public:
      int real;
      int imaginary;
      Complex(){

      }
      // oberloaded operator as member function
      Complex operator+(Complex num2){
        Complex sum;
        sum.real=this->real+num2.real;
        sum.imaginary=this->imaginary+num2.imaginary;
        return sum;
      }
};
int main(){
    int real1,real2;
    int img1,img2;
    cout<<" enter real part of x ";
    cin>>real1;
    cout<<"enter img part of x ";
    cin>>img1;
    cout<<"enter real part of y ";
    cin>>real2;
    cout<<"enter img part of  y ";
    cin>>img2;
    Complex num1;
    Complex num2;
    num1.real=real1;
    num1.imaginary=img1;
    num2.real=real1;
    num2.imaginary=img2;
    Complex num3;
    num3=num1+num2;
    cout<<num3.real<<endl;
    cout<<num3.imaginary<<endl;
}