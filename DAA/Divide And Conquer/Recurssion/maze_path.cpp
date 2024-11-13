#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int maze(int i,int j,int n,int m){
    if(i==n-1 && j==m-1){
        return 1;
    }
    if(i==n || j==m){
        return 0;
    }
    return maze(i+1,j,n,m)+maze(i,j+1,n,m);
}
int main(){
    cout<<maze(0,0,2,2);
}