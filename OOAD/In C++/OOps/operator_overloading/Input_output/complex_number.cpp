#include<iostream>
#include<iomanip>
using namespace std;

class complex{
    friend ostream &operator<<(ostream &, complex &);
    friend istream &operator>>(istream &, complex &);
    public:
    int real;
    int img;
};

ostream &operator<<(ostream &out, complex &c){
    out<<c.real<<"+"<<c.img<<"i";
    return out;
}
istream &operator>>(istream &in, complex &c){
    in>>c.real;
    in.ignore();
    in>>c.img;
    return in;
}
int main(){
    complex c;
    cin>>c;
    cout<<c<<endl;
    cout<<c.img<<endl;
    cout<<c.real<<endl;
}