#include<iostream>
using namespace std;
void print(int n){
    if(n==0) return ;
    print(n-1);
    cout<<n<<" ";
}
void print_para(int n,int i){
    if(i<=n){
        cout<<i<<" ";
        print_para(n,i+1);
    }
}
int main(){
    print(4);
    cout<<endl;
    print_para(4,1);
}