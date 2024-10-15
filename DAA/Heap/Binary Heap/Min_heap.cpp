#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int left(int i){
    return 2*i;
}
int right(int i){
    return 2*i+1;
}
int Min_heap(vector<int>&arr,int i){
    int  l=left(i);
    int r=right(i);
    int min;
    if(l<arr.size() && arr[l]<arr[i]){
        min=l;
    }
    else{
        min=i;
    }
    if(r<arr.size() && arr[r]<=arr[i]){
        min=r;
    }
    if(min!=i){
        swap(arr[i],arr[min]);
        Min_heap(arr,min);
    }
}
void Build_heap(vector<int>&arr){
    for(int i=arr.size()/2 ;i>=0;--i){
        Min_heap(arr,i);
    }
}
int main(){
     vector<int>arr;
    int n;
    cout<<"enter no of element :";
    cin>>n;
    cout<<"enter elements :"<<endl;
    for(int i=0;i<n;++i){
        int val;
        cin>>val;
        arr.push_back(val);
    }
    Build_heap(arr);
    for(int i=0;i<arr.size();++i){
        cout<<arr[i]<<" ";

    }
}