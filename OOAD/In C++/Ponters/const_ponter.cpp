#include<iostream>
using namespace std;
void fun(int* const &ptr){
    int x=10;
    *ptr=5;
  //  ptr=&x; not allowed 
}
int main(){
    int a=10;
    const int *ptr=&a;
   // fun(5); this can not be possible
    cout<<*ptr<<endl;
}