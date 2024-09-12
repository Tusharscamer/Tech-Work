#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    map<int,list<int>> adjmatrix;
    void add(int u,int v){
        adjmatrix[u].push_back(v);
        adjmatrix[v].push_back(u);
    }
    void print(){
          for(auto i: adjmatrix){
               cout<<i.first<<"-> ";
               for(auto j: i.second){
                   cout<<j<<" ";
               }
               cout<<endl;
          }
    }
};
int main(){
    graph g;
    int src,dest;
    int edges;
    cout<<"enter noo of edges :";
    cin>>edges;
    for(int i=0;i<edges;++i){
        cin>>src>>dest;
        g.add(src,dest);
    }
    g.print();
}