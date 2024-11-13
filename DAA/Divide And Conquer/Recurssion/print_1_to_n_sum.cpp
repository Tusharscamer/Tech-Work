#include<iostream>
using namespace std;
int sum(int n){
    if(n==1) return 1;
    return n+sum(n-1);
}
int sum_para(int n,int s){
    if(n==1) return 1;
    return s=n+sum_para(n-1,s);
}
int main(){
    cout<<sum(4);
    cout<<endl;
    cout<<sum_para(4,0);
}