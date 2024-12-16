#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int multiplay(int &a){
    a=a*2;
}
int main(){
    vector<int> arr;
    int n=5;
    int element;
    for(int i=0;i<n;++i){
       cin>>element;
       arr.push_back(element);
    }
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    for_each(arr.begin(),arr.end(),[](int i){
        cout<<i<<" ";
    });
    cout<<endl;
    for_each(arr.begin(),arr.end(),[](int &i){
        i=i*2;
    });
    for_each(arr.begin(),arr.end(),[](int i){
        cout<<i<<" ";
    });
    cout<<endl;
    for_each(arr.begin(),arr.end(),[](int &a){
        multiplay(a);
    });
    for_each(arr.begin(),arr.end(),[](int a){
        cout<<a<<" ";
    });
}