#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int cutRod(vector<int> price,int n){
    vector<int>r(n+1,INT_MIN);
     int q=INT_MIN;
    if (r[n]>=0) return r[n];
    if(n==0){
        q=0;
    }
    else {
        q=INT_MIN;
        for(int i=1;i<=n;++i){
            q=max(q,price[i]+cutRod(price,n-i));
        }
    }
    r[n]=q;
    return q;
}
int main(){
    int n;
    cout<<"Enter the length of rod :";
    cin>>n;
    int val;
    vector<int> price;
    price.push_back(0);
    cout<<"Enter the price of rod for each length 1-"<<n<<":";
    for(int i=0;i<n;i++){
        cin>>val;
        price.push_back(val);
    }
    cout<<"max price of rod is :"<<cutRod(price,n);
}