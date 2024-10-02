//undirected
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<string,list<pair<string,int>>> adjlist;
    unordered_map<string,int>dist;
    unordered_map<string ,string >parent;
    unordered_map<string,string> color;

    // intializing Graph
    void addEdge(string u,string v,int w){
        adjlist[u].push_back(make_pair(v,w));
         adjlist[v].push_back(make_pair(u,w));
    }

    // Applying BFS
    void Bfs(string src){
         for(auto i:adjlist){
             string U=i.first;
             dist[U]=1000;
             parent[U]="NIL";
             color[U]="White";
         }
         dist[src]=0;
         queue<string> Q;
         Q.push(src);
         while(!Q.empty()){
            string U=Q.front();
            Q.pop();
            for(auto i:adjlist[U]){
               if(color[i.first]=="White"){
                   string V=i.first;
                   int E=i.second;
                   color[V]="Green";
                   parent[V]=U;
                   dist[V]=dist[U]+E;
                   Q.push(V);
               }
            }
            color[U]="black";
            cout<<"Vertex :"<<U<<" parent :"<<parent[U]<<" distance :"<<dist[U]<<endl;
        }
    }

    // Shortest Path between Src And Dest
    void print_path(string src,string dest){
        if(src==dest){
            cout<<src<<" ";
        }
        else if(parent[dest]=="NIL"){
            cout<<" path doest not exist :";
            return ;
        }
        else{
            print_path(src,parent[dest]);
            cout<<dest<<" ";
        }
    }
};
int main(){
    int E;
    Graph G;
    cout<<" Enter no of edges :";
    cin>>E;
    string src,dest;
    int weight;
    cout<<"enter : Src , Dest , Weight :"<<endl;
    for(int i=0;i<E;++i){
        cin>>src;
        cin>>dest;
        cin>>weight;
        G.addEdge(src,dest,weight);
    }
    string s;
    cout<<"specify source :";
    cin>>s;
    G.Bfs(s);
    string d;
    cout<<"specify destination :";
    cin>>d;
    G.print_path(s,d);
}