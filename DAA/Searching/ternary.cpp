#include<iostream>
#include<vector>
using namespace std;
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
    int low=0;
    int high=n-1;
    cout<<"enter value fo find :";
    cin>>val;
    int index=-1;
    while(low<=high){
        int mid1=low+(high-low)/2;
        int mid2=high-(high-low)/2;
        if(arr[mid1]==val){
           index=mid1;
           break;
        }
        else if(arr[mid2]==val){
            index=mid2;
            break;
        }
        else if(val<arr[mid1]){
            high=mid1-1;
        }
        else if(val>arr[mid2]){
            low=mid2+1;
        }
        else if(val>arr[mid1] && val<arr[mid2]){
            low=mid1+1;
            high=mid2-1;
        }
    }
    if(index!=-1){
        cout<<"value at index "<<index;
    }
    else{
        cout<<"value not found";
    }
}