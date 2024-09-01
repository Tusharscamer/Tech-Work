#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr={1,2,3,4,5,6,7,8,9,10};
    int target=5;
    int low=0;
    int high=arr.size()-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            ans=mid;
            break;
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    if(ans==-1){
        
    }
    else{
    return 0;
}