#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> counting_sort(vector<int>&arr){
      vector<int>brr(arr.size(),0);
      int maxi=INT_MIN;
      for(int i=0;i<arr.size();++i){
          maxi=max(arr[i],maxi);
      } 
      vector<int>crr(maxi+1,0);
      for(int i=0;i<arr.size();++i){
          crr[arr[i]]=crr[arr[i]]+1;
      }
      for(int i=1;i<crr.size();++i){
        crr[i] =crr[i]+crr[i-1];
      }
      for(int i=arr.size()-1;i>=0;--i){
         brr[crr[arr[i]]-1]=arr[i];
         crr[arr[i]] -=1;
      }
      return brr;
}
int main(){
    int n;
    cout<<"size of arry :";
    cin>>n;
    cout<<"enter numbers "<<endl;
    int val;
    vector<int>arr;
    for(int i=0;i<n;++i){
        cin>>val;
        arr.push_back(val);
    }
    vector<int>brr=counting_sort(arr);
    for(int i=0;i<brr.size();++i){
        cout<<brr[i]<<" "; 
    }
}