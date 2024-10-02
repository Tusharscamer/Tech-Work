#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int cutRod(vector<int> price,int n){
    vector<int>r(n+1,INT_MIN);
    r[0]=0;
    int q;
    for(int j=1;j<=n;++j){
        q=INT_MIN;
        for(int i=1;i<=j;++i){
            q=max(q,price[i]+r[j-i]);
        }
        r[j]=q;
    }
    return r[n];
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