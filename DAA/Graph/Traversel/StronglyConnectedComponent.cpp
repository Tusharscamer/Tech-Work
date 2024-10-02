#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<string,list<pair<string,int>>> adjlist;
    unordered_map<string,int>dist;
    unordered_map<string ,string >parent;
    unordered_map<string,string> color;
    unordered_map<string,int> Time;
    int time;
    void addEdge(string u,string v,int w){
        adjlist[u].push_back(make_pair(v,w));
    }
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
    }
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
            cout<<endl;
        }
    }
};
int main(){
    int E;
    Graph G1;
    string u,v;
    int w;
    cout<<"Enter no of edges : ";
    cin>>E;
    cout<<"Enter edges : src , dest , weight"<<endl;
    for(int i=0;i<E;++i){
        cin>>u>>v>>w;
        G1.addEdge(u,v,w);
    }
    G1.Dfs();
    Graph G2;
    for(auto i:G1.adjlist){
        string U=i.first;
        for(auto j:G1.adjlist[U]){
            G2.addEdge(j.first,U,j.second);
        }
    }
    G2.Dfs();
}