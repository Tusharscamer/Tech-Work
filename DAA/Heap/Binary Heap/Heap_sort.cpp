// invalid code 
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
int Max_heapify(vector<int>&arr,int i,int n){
     int l=Left(i);
     int r=right(i);
     int largest;
     if ( l<n && arr[l]>arr[i]){
        largest=l;
     }
     else{
        largest=i;
     }
     if(r<n && arr[r]>=arr[i]){
        largest=r;
     }
     if(largest !=i){
        swap(arr[i],arr[largest]);
        Max_heapify(arr,largest,n);
     }
     return 0;
}
void Build_heap(vector<int>&arr){
    for(int i=arr.size()/2;i>=0;--i){
        Max_heapify(arr,i,arr.size());
    }
}
void Heap_sort(vector<int>&arr,int n){
    Build_heap(arr);
    for(int i=arr.size()-1;i>=1;--i){
        swap(arr[i],arr[0]);
        --n;
        cout<<arr[0]<<" ";
        Max_heapify(arr,0,n);
    }
}
int main(){
    int n;
    cout<<"enter size : ";
    cin>>n;
    vector<int>arr;
    int val;
    cout<<"enter elements : ";
    for(int i=0;i<n;++i){
        cin>>val;
        arr.push_back(val);
    }
    Build_heap(arr);
    cout<<"building max  heap"<<endl;
    for(int i=0;i<arr.size();++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"heap sort "<<endl;
    Heap_sort(arr,arr.size());
    cout<<endl;
}