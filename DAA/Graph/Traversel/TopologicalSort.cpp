#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<string,list<pair<string,int>>> adjlist;
    unordered_map<string,string>parent;
    unordered_map<string,int>dist;
    unordered_map<string,int>Time;
    unordered_map<string,string>color;
    int time;
    void addEdge(string u,string v,int w){
        adjlist[u].push_back(make_pair(v,w));
    }
    // DFS Visit
    void DfsVisit(string u){
        time++;
        Time[u]=time;
        color[u]="gray";
        for(auto i:adjlist[u]){
            string V=i.first;
            if(color[V]=="White"){
                parent[V]=u;
                DfsVisit(V);
            }
        }
        color[u]="Black";
        time++;
        Time[u]=time;
        cout<<u<<" ";
    }
    // Dfs 
    void Dfs(){
        for(auto i:adjlist){
            string U=i.first;
            parent[U]="NIL";
            color[U]="White";
        }
        time=0;
        for(auto i:adjlist){
            string U=i.first;
            if(color[U]=="White"){
                DfsVisit(U);
            }
        }
    }
    // Topological Sort
    void TopologicalSort(){
        Dfs();
    }
};
int main(){
    int E;
    Graph G;
    string u,v;
    int w;
    cout<<"Enter no of edges : ";
    cin>>E;
    cout<<"Enter edges : src , dest , weight"<<endl;
    for(int i=0;i<E;++i){
        cin>>u>>v>>w;
        G.addEdge(u,v,w);
    }
    G.Dfs();
}