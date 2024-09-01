// Class does not allow us to use their data members directly in static functions.
#include <iostream>
#include <vector>
using namespace std;

class Student{
    public:
    void setdata(int age ,string name){
         Age=age;
         Name=name;
         display();
    }
    static void display(){
       cout<<"you are inside the class";
      // cout<<Age;
    }
    private:
    int Age;
    string Name;
};
int main(){
    Student s1;
    s1.setdata(20,"tushar");
    Student::display();
}