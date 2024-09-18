#include<iostream>
#include<utility>
using namespace std;
template<typename T>
void print(T &&a){
    cout<<a<<endl;
}
int main(){
    int i=0;
    print(i);
    print(4);
}