#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class graph{
    public:
    map<int,list<pair<int,int>>> adjmatrix;
    void add(int src,int dest ,int weight){
        adjmatrix[src].push_back(make_pair(weight,dest));
    }
    void print(){
          for(auto i: adjmatrix){
               cout<<i.first<<"-> ";
               for(auto j: i.second){
                   cout<<"--"<<j.first<<"--"<<j.second<<" ";
               }
               cout<<endl;
          }
    }
};
int main(){
    graph g;
    int src,dest,weight;
    int edges;
    cout<<"enter noo of edges :";
    cin>>edges;
    cout<<"src-> --weight--dest :"<<endl;
    for(int i=0;i<edges;++i){
        cin>>src>>weight>>dest;
        g.add(src,dest,weight);
    }
    g.print();
}