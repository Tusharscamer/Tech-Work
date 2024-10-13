#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;
int partition(vector<int> &arr, int l, int h){
    int pivot = l+(rand()%(h-l+1));
    swap(arr[pivot], arr[h]);
    int i=l-1;
    for(int j=l;j<=h-1;j++){
        if(arr[j]<arr[h]){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[h]);
    return i+1;
}
int kthSmallest(vector<int> &arr, int l, int h, int k){
    if(l==h){
        return arr[l];
    }
    int p = partition(arr, l, h);
    int n= p-l+1;
    if(n==k){
        return arr[p];
    }
    if(n>k){
        return kthSmallest(arr,l,p-1,k);
    }
    else{
        return kthSmallest(arr,p+1,h,k-n);
    }
}
int main(){
    vector<int> arr;
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
    srand(time(0));
    cout<<kthSmallest(arr,0,n-1,k);
    return 0;
}