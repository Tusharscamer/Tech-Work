#include<iostream>
using namespace std;
int main(){
    int r1,c1;
    int r2,c2;
    int val;
    cout<<"enter row and column or matrix 1 ";
    cin>>r1;
    cin>>c1;
    cout<<"enter row and coulum of matrix 2 ";
    cin>>r2;
    cin>>c2;
    int arr[r1][c1];
    int brr[r2][c2];
    for(int i=0;i<r1;++i){
        for(int j=0;j<c1;++j){
            cout<<"enter element ";
            cin>>val;
            arr[i][j]=val;
        }
    }
    for(int i=0;i<r2;++i){
        for(int j=0;i<c2;++j){
            cout<<"enter element no  ";
            cin>>val;
            brr[i][j]=val;
        }
    }
    int crr[r1][c1];
    for(int i=0;i<r1;++i){
        for(int j=0;j<c1;++j){
            crr[i][j]=arr[i][j]+brr[i][j];
        }
    }
    for(int i=0;i<r1;++i){
       for(int j=0;j<c1;++j){
        cout<< crr[i][j]<<" ";
       }
    }
    int arr1[c1][r1];
    for(int i=0;i<r1;++i){
        for(int j=0;j<c1;++j){
            arr1[j][i]=arr[i][j];

        }
    }
    // transporse 

}