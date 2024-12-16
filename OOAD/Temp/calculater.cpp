#include<iostream>
#include<bits/stdc++.h>
using namespace std;
template <typename C>
class Cal{
    private :
    int num;
    public :
    C getnum(){
        return num;
    } 
    void setnum(C n){
        num=n;
    }
    friend ostream &operator<<(ostream& out , Cal<C> &obj){
        out<<obj.num;
        return out;
    }
    friend istream &operator>>(istream& in , Cal<C> &obj){
        in>>obj.num;
        return in ;
    }
};
template <typename C> Cal<C> operator+(Cal<C> &obj1,Cal<C> &obj2){
    Cal<C> obj;
    obj.setnum(obj1.getnum()+obj2.getnum());
    return obj;
}
template <typename C> Cal<C> operator-(Cal<C> &obj1,Cal<C> &obj2){
    Cal<C> obj;
    obj.setnum(obj1.getnum()-obj2.getnum());
    return obj;
}
int main(){
    Cal<int> d1;
    cin>>d1;
    Cal<int> d2;
    cin>>d2;
    Cal<int> d3=d1+d2;
    cout<<d3;
}
