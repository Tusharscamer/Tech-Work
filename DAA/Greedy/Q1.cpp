#include<bits/stdc++.h>
using namespace std;
bool comp(vector<int>a,vector<int>b){
    int a1=a[1];
    int b1=b[1];
    return a1>b1;
}
int main(){
    vector<vector<int>>arr={{1,10},{2,5},{3,15}};
    sort(arr.begin(),arr.end(),comp);
    int n=arr.size();
    for(int i=0;i<n;i++){
        cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
    }
}