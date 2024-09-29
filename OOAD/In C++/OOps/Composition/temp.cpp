// we can access the member function of composite class from the derived class
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class circle  {
public:
    void area(int r){
         print(3 * r * r);
    }
    void print(int a) {
        cout << "I'm a circle with "<<a<< endl;
    }
    void perameter(){
        cout<<"peramereter"<<endl;
    }
    int r;
    int midpoint;
    int d;
    circle(int r, int d, int midpoint){
        this->r = r;
        this->d = d;
        this->midpoint = midpoint;
    }
};
class shape {
public:
   circle c1;
    shape(int r, int d, int midpoint) : c1(r, d, midpoint) {// usiing list initializer to initialize the object
   }
}; 
int main() {
    shape s1(5,4,3);
    s1.c1.area(5);
    s1.c1.print(4);
    s1.c1.perameter();
}
