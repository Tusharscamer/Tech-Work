// if we use const operator in copy assignment operator it will not work
#include<iostream>
using namespace std;
class Complex{
    public:
    int r;
    int* i;
    // Complex operator=(Complex obj){//  we cannot do this
    //    Complex newi;
    //     newi.r=obj.r;
    //     newi.i=obj.i;
    //     return newi;
    // }

    Complex operator=( Complex obj){
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
    const Complex num3=num1;// const object using copy assignment operator
    cout<<num3.r<<" "<<*num3.i<<endl;
}