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
int Max_heapify(vector<int>&arr,int i,int &n){
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
void Build_heap(vector<int>&arr,int &n){
    for(int i=arr.size()/2;i>=0;--i){
        Max_heapify(arr,i,n);
    }
}
int Extract_max(vector<int>&arr,int &n){
    int max=arr[0];
    arr[0]=arr[arr.size()-1];
    --n;
    Max_heapify(arr,0,n);
    return max;
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
    cout<<"Build Heap "<<endl;
    Build_heap(arr,n);
    for(int i=0;i<arr.size();++i){
        cout<<arr[i]<<" ";

    }
    cout<<"Extracting max "<<endl;
    for(int i=0;i<arr.size();++i){
        cout<<Extract_max(arr,n)<<" ";
    }

}