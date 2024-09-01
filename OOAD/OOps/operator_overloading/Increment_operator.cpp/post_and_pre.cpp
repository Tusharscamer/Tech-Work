#include<iostream>
using namespace std;
class Math{
    private :
     int val;
     public:
     Math(){

     }
     Math(int i){
        val=i;
     }
    // pre increment 
    Math operator++(){
        ++val;
        return *this;
    }
    Math operator++(int ){
        Math restore=*this;
        ++val;
        return restore;
    }
    void show(){
        cout<<val<<endl;
    }
};
int main(){
    Math s(4);
    s.show();
    s++;
    s.show();
    // post increment
    Math t=s++;
    s.show();
    t.show();
    t=++s;
    // pre increment 
    t.show();
}