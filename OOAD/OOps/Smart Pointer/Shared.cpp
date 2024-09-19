#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Hello{    
    public:
    void fun(){
        cout<<"Hello"<<endl;
    }
};
int main(){
    shared_ptr<Hello> obj(new Hello());
    obj->fun();
}