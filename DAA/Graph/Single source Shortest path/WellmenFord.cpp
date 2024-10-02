#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map <string,list<pair<string,int>>> adjlist;
    unordered_map<string ,int> dist;
    unordered_map<string ,string> parent;
    void addEdge(string u,string v,int weight){
        adjlist[u].push_back(make_pair(v,weight));
    }
    bool wellmenford(string src){
        for(auto i: adjlist){
            dist[i.first]=10000;
            parent[i.first]=-1;
        }
        dist[src]=0;
        for(int a=0;a<adjlist.size();++a){
            for(auto i:adjlist){
            string U=i.first;
            for(auto j:i.second){
                string  V=j.first;
                int E=j.second;
                if(dist[U]!=10000 && dist[V]>=dist[U]+E ){
                    dist[V]=dist[U]+E;
                    parent[V]=U;
                }
            }
          }
       }
       for(auto i:adjlist){
            string U=i.first;
            for(auto j:i.second){
                string  V=j.first;
                int E=j.second;
                if(dist[U]!=10000 && dist[V]>=dist[U]+E ){
                   return false;
                }
            }
       }
       return true;
    }
    void print( ){
         for(auto i:adjlist){
             cout<<"node "<<i.first<<" distance "<<dist[i.first]<<" parent "<<parent[i.first]<<endl;
         }
    }
};
int main(){
    int E;
    Graph G;
    cout<<"enter no of edge :";
    cin>>E;
    string src,dest;
    int weight;
    cout<<"enter : src , dest ,weight";
    for(int i=0;i<E;++i){
         cin>>src;
         cin>>dest;
         cin>>weight;
         G.addEdge(src,dest,weight);
    }
    string s;
    cout<<"Specify  Source :";
    cin>>s;
    bool flag=G.wellmenford(s);
    if(flag==true){
          G.print();
    }
    else{
        cout<<"Graph Exist Negative Weight cycle "<<endl;
    }

}