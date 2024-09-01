#include<iostream>
#include<vector>
using namespace std;
struct MinMax{
    int min;
    int max;
};
MinMax getMinMax(vector<int>arr,int low,int high){
    MinMax obj;
    if(low==high){
        obj.min=arr[low];
        obj.max=arr[high];
        return obj;
    }
    if(low==high+1){
        if(arr[low]<arr[high]){
            obj.min=arr[low];
            obj.max=arr[high];
        }
        else{
            obj.min=arr[high];
            obj.min=arr[low];
        }
        return obj;
    }
    int mid=(low+high)/2;
    MinMax leftResult= getMinMax(arr,low,mid);
    MinMax rightResult= getMinMax(arr,mid+1,high);

    obj.min=min(leftResult.min,rightResult.min);
    obj.max=max(leftResult.max,rightResult.max);
    return obj;
}
int main(){
    int n;
    cout<<"enter how many element :";
    cin>>n;
    vector<int>arr;
    int val;
    for(int i=0;i<n;++i){
        cout<<"enter element :";
        cin>>val;
        arr.push_back(val);
    }
    MinMax minmax = getMinMax(arr,0,n-1);
    cout<<"min : "<<minmax.min<<" max : "<<minmax.max;
}