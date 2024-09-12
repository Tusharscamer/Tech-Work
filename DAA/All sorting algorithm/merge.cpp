#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void merge(vector<int> &arr,int low ,int mid,int high){
   int n1=mid-low+1;
   int n2=high-mid;
   vector<int>num1;
   vector<int>num2;
   for(int i=0;i<n1;++i){
       num1.push_back(arr[low+i]);
   }
   for(int i=0;i<n2;++i){
      num2.push_back(arr[mid+i+1]);
   }
   int i=0;
   int j=0;
   int k=low;
    while(i<n1 && j<n2){
      if(num1[i]<=num2[j]){
        arr[k]=num1[i];
        ++i;
      }
      else{
        arr[k]=num2[j];
        ++j;
      }
      ++k;
   }
   while(i<n1){
      arr[k]=num1[i];
      ++k;
      ++i;
   }
    while(j<n2){
      arr[k]=num1[j];
      ++j;
      ++k;
   }
   
}
void merge_sort(vector<int>&arr,int low ,int high){
    if(low<high){
          int mid=low+(high-low)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
    int n;
    cout<<"enter size :";
    cin>>n;
    vector<int> arr;
    int val;
    for(int i=0;i<n;++i){
        cin>>val;
        arr.push_back(val);
    }
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
}