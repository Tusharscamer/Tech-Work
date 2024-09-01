#include<iostream>
using namespace std;
class num{
    public:
    int c;
    int b;
    int a;
    num(){

    }
    num(int a,int b,int c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
    void print(){
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
};
int main(){
    num n(1,2,3);;
    n={4,5,6};
    n.print();
}