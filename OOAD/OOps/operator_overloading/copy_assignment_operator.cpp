#include<iostream>
using namespace std;
class Complex{
    public:
    int r;
    int* i;
    Complex operator=(Complex obj){
        this->r=obj.r;
        this->i=obj.i;
    }
};
int main(){
    Complex num1;
    num1.r=4;
    int u=3;
    num1.i=new int(3);
    Complex num2;
    num2=num1;
    cout<<num2.r<<" "<<*num2.i<<endl;
    num1.i=new int(4);
    cout<<num1.r<<" "<<*num1.i<<endl;
    cout<<num2.r<<" "<<*num2.i<<endl;
    Complex num3=num2;
    cout<<num3.r<<" "<<*num3.i<<endl;
}