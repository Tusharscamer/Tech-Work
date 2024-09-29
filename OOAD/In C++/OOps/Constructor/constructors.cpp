#include<iostream>
using namespace std;
class student{
    public:
    int age;
    string name;
    student(){ //default constructor}
        
    }
    student(string n,int a){
        age = a;
        name = n;
        cout<<"object is successfully created"<<endl;
    }
};
int main(){
    student s1("Tushar", 21);
    student s2("Trisha",14);
    student s3;
    s3.name = "Shubham";
    s3.age = 19;
    cout<<s1.name<<" "<<s1.age<<endl;
    cout<<s2.name<<" "<<s2.age<<endl;
    cout<<s3.name<<" "<<s3.age<<endl;
    return 0;
}