
#include<iostream>
using namespace std;
class test{
    public:
    int data;
    test(int a){
        this->data=a;
    }
    void print(){
        cout<<data<<endl;
    }
};
test operator++(test &t){
    t.data++;
    return t;
}
test operator++(test &t,int){
    test temp=t;
    t.data++;
    return temp;
}
int main(){
    test t(10);
    t.print();
    test t1=t++;
    t1.print();
    t1=++t;
    t.print();
    t1.print();
}
