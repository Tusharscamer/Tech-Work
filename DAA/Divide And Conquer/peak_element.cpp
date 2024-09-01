#include<iostream>
#include<vector>
using namespace std;
int getPeak(vector<int> &arr,int low,int high,int n){
    int mid=low+(high-low)/2;
    if(mid==0 || arr[mid-1]<=arr[mid] && mid==n-1 || arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid]){
        return mid;
    }
    else if(mid>0 && arr[mid-1]>arr[mid]){
        return getPeak(arr,low,mid-1,n);
    }
    else {
        return getPeak(arr,mid+1,high,n);
    }
}
int main(){
       int n;
       cout<<"how many element :";
       cin>>n;
       vector<int> arr;
       int val;
       for(int i=0;i<n;++i){
          cout<<"enter value :";
          cin>>val;
          arr.push_back(val);
       }
       cout<<getPeak(arr,0,n-1,n-1);
}