#include<bits/stdc++.h>
using namespace std;
template <typename C>
class arry{
    private:
    vector<C*>a;
    int count=0;
    public:
    void push_back(C e){
        a.push_back(new C(e));
        ++count;
    }
    arry(){

    }
    arry(arry<C> &arr){
        for(int i=0;i<count;++i){
            arr.a[i]=new C(this->a[i]);
        }
        arr.count=this->count;
    }
    C& operator[](int index){
        return *a[index];
    }
};
int main(){
    arry<int> b;
    int element;
    int n;
    cout<<"enter no of element :";
    cin>>n;
    cout<<"enter elements :";
    for(int i=0;i<n;++i){
        cin>>element;
        b.push_back(element);
    }
    for(int i=0;i<n;++i){
        cout<<b[i]<<" ";
    }
}