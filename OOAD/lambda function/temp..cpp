#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a=0;
    int b=4;
    int c=5;
    auto lambda=[=] (int sum){
       sum=a+b+c;
        return sum;
    };
    int i=0;
    int sum=lambda(i);
    cout<<sum;
}