#include<iostream>
using namespace std;
void Robin_karp(string T,string P){
    int m=T.size();
    int n=P.size();
    int q=101;
    int d=256;
    int h=1;
    int p=0;
    int t=0;
    int i,j;
    for( i=0;i<m-1;++i){
        t=(d*t+T[i])%q;
    }
    for( i=0;i<n-1;++i){
        p=(d*p+P[i])%q;
    }
    for( i=0;i<=m-n;++i){
        if(t==p){
            for( j=0;i<n;++i){
                if(T[i]!=P[i]){
                    break;
                }
            }
            if(j==m){
                cout<<i<<endl;
            }
            if(i<m-n){
                t=(d*(t-T[i]*h)+T[i+m])%q;
                if(t<h){
                    t=t+q;
                }
            }
        }
    }
}
int main(){
    string T;
    string P;
    cout<<"text : ";
    cin>>T;
    cout<<"pattern : ";
    cin>>P;
}
