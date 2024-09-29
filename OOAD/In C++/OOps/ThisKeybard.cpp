#include<iostream>
using namespace std;
class Student{
    public:
    int age;
    string name;
    Student(int age,string name){
       this->age = age; 
       this->name=name;
    }

};
int main(){
    Student s1(21,"Tushar");
    cout<<s1.age<<" "<<s1.name<<endl;
    return 0;  
}