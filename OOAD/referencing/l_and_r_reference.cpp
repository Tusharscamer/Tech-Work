#include<iostream>
#include<utility>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a=0;
    int b=4;
    int &&c=++a+b;
    ++a+b;
    cout<<c;
    int &d=b;
    b=1;
    cout<<d;
    vector<int>arr;
    arr.push_back(4);
    int &e=arr[0];
    arr[0]=-1;
    cout<<e;
    e=45;
    cout<<arr[0];
}
