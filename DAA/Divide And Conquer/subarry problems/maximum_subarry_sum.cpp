#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Sum {
    public:
    int low;
    int high;
    int sum;
    Sum(){

    }
    Sum (int low,int high,int sum){
        this->low=low;
        this->high=high;
        this->sum=sum;
    }
};
Sum find_crossing(vector<int>arr,int low,int mid,int high){
    Sum cross;
    int left_sum=INT_MIN;
    int sum=0;
    for(int i=mid;i>=low;--i){
        
    }
}
Sum max_subarry(vector<int>arr,int low,int high ){
    if(low==high){
        return {low,high,arr[low]};
    }
    else{
        int mid=low+(high-low)/2;
        Sum left;
        left=max_subarry(arr,low,mid);
        Sum right=max_subarry(arr,mid+1,high);
        Sum crossing;
        crossing=find_crossing(arr,low,mid,high);
        if(left.sum>right.sum && left.sum>crossing.sum){
              return left;
        }
        else if(right.sum>crossing.sum && right.sum>left.sum){
            return right;
        }
        else{
            return crossing;
        }
    }
}