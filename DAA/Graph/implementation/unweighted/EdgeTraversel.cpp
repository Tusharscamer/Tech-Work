#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    map<int,pair<int,int>> adjmatrix;
    void add(int u,int v,int e){
        adjmatrix[e]=make_pair(u,v);
    }
    void print(){
          for(auto i: adjmatrix){
               cout<<"edge"<<i.first<<" ";
               cout<<"src"<<i.second.first<<" "<<"dest"<<i.second.second;
               cout<<endl;
          }
    }
    void wellmenford(int src){
           
    }
};
int main(){
    graph g;
    int src,dest;
    int edges;
    cout<<"enter noo of edges :";
    cin>>edges;
    for(int i=0;i<edges;++i){
        cin>>edges;
        cin>>src>>dest;
        g.add(src,dest,edges);
    }
    g.print();
}