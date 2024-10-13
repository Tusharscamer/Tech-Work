#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&arr,int l,int h,int medianOfmed){
    int i=l;
    for(i;i<h;i++){
        if(arr[i]<=medianOfmed){
            break;
        }
    }
    swap(arr[i],arr[h]);
    i=l-1;
    for(int j=l;j<h-1;j++){
        if(arr[j]<medianOfmed){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i;
}
int findMedian(vector<int>&arr,int length){
      sort(arr.begin(),arr.begin()+length);
      return arr[(length)/2];
}
int KthSmallest(vector<int>arr,int l,int h,int k){
   if(k>0 && k<=h-l+1){
          int n=h-l+1;
    int i;
    vector<int>med((n+4)/5);
    for(i=0;i<(n)/5;i++){
          vector<int> group(arr.begin() + l + i * 5, arr.begin() + l + i * 5 + 5);
         med[i]=findMedian(group,5);
    }
    if(i*5<n){
        vector<int> group(arr.begin() + l + i * 5, arr.begin() + l + i * 5 + n % 5);
        med[i] = findMedian(group, n % 5); 
        i++; 

    }
    int median=(i==1)?med[0]:KthSmallest(arr,0,i-1,i/2);
    int pos=partition(arr,l,h,median);
    if(pos-1==k-1){
        return arr[pos];
    }
    else if(pos-1>k-1){
        return KthSmallest(arr,l,pos-1,k);
    }
    else{
        return KthSmallest(arr,pos+1,h,k-pos+l-1);
    }
   }
   return INT_MAX;
}
int main(){
    vector<int>arr;
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the elements of array: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int k;
    cout<<"Enter the kth smallest element: ";
    cin>>k;
    cout<<KthSmallest(arr,0,n-1,k);
    return 0;
}