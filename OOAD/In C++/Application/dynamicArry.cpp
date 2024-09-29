/// dynamic array with static size
// deep and shallow copy 
// type convertion is also there 
#include<iostream>
using namespace std;
class Employee{
    private:
    string *arr[10];
     int count;
    public:
    Employee(string name ){
        count=0;
        arr[count++]= new string(name);
    }
    void push_back(string s){
        arr[count++]= new string (s);
    }

    // this is shallow copy
    Employee(Employee &obj){
          count=obj.count;
          for(int i=0;i<this->count;++i){
             arr[i]=obj.arr[i];
          }
    }
    
    // this is deep copy
    // Employee(Employee &obj){
    //      count=obj.count;
    //       for(int i=0;i<this->count;++i){
    //          arr[i]=new string(*obj.arr[i]);
    //       }
    // }5
    friend ostream &operator<<(ostream &out,Employee &obj){
        for(int i=0;i<obj.count;i++){
            out<<*obj.arr[i]<<" ";

        }
        out<<endl;
        return out;
    }
     string& operator[](int index) {
        if (index >= 0 && index <=count) {
            return *arr[index];  // Return reference to the element
        }
          throw out_of_range("Index out of range");
    }
    operator string();
};
Employee::operator string(){
    string s;
    for(int i=0;i<count;i++){
        s+=*arr[i]+" ";
    }
    return string(s);
}
int main(){
     Employee E1("Tushar");
     E1.push_back("web developer");
     E1.push_back("Android developer");
     cout<<E1;
     Employee E2=E1;
     cout<<E2;
     E1[1]="data science enginneer";
     cout<<E1;
     cout<<E2;
     string s=E1;
     cout<<s;
}