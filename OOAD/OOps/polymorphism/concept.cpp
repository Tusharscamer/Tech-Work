// function's that declared in derived class but not virtual they exist but we
// can not access them in main

// in main we can omly acess virtual function and base class member functions

// if we want to access them then we have to use dynamic_cast 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class shape {
public:
   virtual void area(int l) {
        cout<< l * l;
    }
    void draw(){
        cout<<"draw shape"<<endl;
    }
};
class circle : public shape {
public:
    void area(int r) override{
         print(3 * r * r);
    }
    void print(int a) {
        cout << "I'm a circle with "<<a<< endl;
    }
    void perameter(){
        cout<<"peramereter"<<endl;
    }
};d
int main() {
    circle c1;
    shape *s=&c1;
    s->area(5);
    shape *s1=new circle();
    s1->area(5);
    s1->draw();
    circle *c = dynamic_cast<circle*>(s1);
    c->print(4);
    s1->area(5);
}
