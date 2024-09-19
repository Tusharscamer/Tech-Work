#include<iostream>
using namespace std;
template<typename T>
class cal{
    public:
    T num;
    cal(T n){
        num=n;
    }
    display(){
        cout<<num<<endl;
    }   
};
class Smartptr{
    public:
     T* ptr;
     Smartptr(T* p=NULL){
         ptr=p;
     }
     ~Smartptr(){
        delete ptr;
     }
     T& operator*(){
        return *ptr;
     }
     T* operator->(){ // this is for what ?
        return ptr;
    }
};
int main(){
    Smartptr<int> p1(new int());
    *p1=29;
    cout<<*p1<<endl;
    //cout<<p1->ptr; // gives error why ?
    cout<<p1.ptr;
    cal <int> obj(5);
    p1=&obj;
    p1->display();
}