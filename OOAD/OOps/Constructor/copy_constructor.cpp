#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Complex{
    public:
    int r;
    int i;
    Complex(){

    }
    Complex(Complex &obj){
        this->r=obj.r;
        this->i=obj.i;
    }
};
int main(){
     Complex c1;
     c1.r=4;
     c1.i=5;
     Complex c2=c1;
     cout<<c2.r<<" "<<c2.i;
}