#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int Parent(int i){
    return i/2;
}
int Left(int i){
    return 2*i;
}
int right(int i){
    return 2*i+1;
}
int Max_heapify(vector<int>&arr,int i){
     int l=Left(i);
     int r=right(i);
     int largest;
     if ( l<arr.size() && arr[l]>arr[i]){
        largest=l;
     }
     else{
        largest=i;
     }
     if(r<arr.size() && arr[r]>=arr[i]){
        largest=r;
     }
     if(largest !=i){
        swap(arr[i],arr[largest]);
        Max_heapify(arr,largest);
     }
     return 0;
}
void Build_heap(vector<int>&arr){
    for(int i=arr.size()/2;i>=0;--i){
        Max_heapify(arr,i);
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