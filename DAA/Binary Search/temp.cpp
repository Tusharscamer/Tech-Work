#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int main(){
    int x=4;
    int n=((int)log10(x)+1);
    cout<<n<<endl;
   while(x>0){
    int a=x/(pow(10,n-1));
    if(n==1){
        cout<<x<<endl;
    }
    else{
        cout<<a<<endl;
    }
    cout<<n<<"this is "<<endl;
    x=x%(int)(pow(10,n-1));
    --n;
   }
   cout<<min(1,2,3);
}