#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr={1,1,2,2,2,3,3,3,4,4,5,6,7,8,9,10,10};
    int target=1;
    int low=0;
    int high=arr.size()-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            if(mid==0){
                ans=mid;
                break;
            }
            else if(arr[mid-1]!=target){
                ans=mid;
                break;
            }
            else {
                high=mid-1;
            }
        }
        else if(arr[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
     cout<<ans<<endl;
    return 0;
}