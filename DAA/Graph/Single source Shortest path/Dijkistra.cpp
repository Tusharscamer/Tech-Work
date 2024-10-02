#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map <string,list<pair<string,int>>> adjlist;
    unordered_map <string,int> dist;
    unordered_map <string,string> parent;
    void addEdge(string u,string v,int w){
        adjlist[u].push_back(make_pair(v,w));
    }
    void dijkistra(string src){
        for(auto i: adjlist){
             string U=i.first;
             dist[U]=1000;
             parent[U]=-1;
        }
        dist[src]=0;
        priority_queue<string,int> pq;
        for(i:adjlist){
            pq.push(make_pair(i.first,dist[i.first]));
        }
        while(!pq.empty()){
            string U=pq.top();
            pq.pop();
            for(auto i:adjlist[U]){
                string V=i.first;
                int E=i.second;
                if(dist[U]!=1000 && dist[V]>=dist[U]+E){
                    dist[V]=dist[U]+E;
                    parent[V]=U;
                }
            }
        }
    }
    void print(){
        for(auto i:adjlist){
            cout<<"Vertex :"<<i.first<<" distance :"<<dist[i.first]<<" parent :"<<parent[i.first]<<endl;
        }
    }
};
int main(){
    Graph G;
    int E;
    cout<<"enter no of edges :";
    cin>>E;
    string src,dest;
    int weight;
    cout<<"enter : src dest weight "<<endl;
    for(int i=0;i<E;++i){
        cin>>src;
        cin>>dest;
        cin>>weight;
        G.addEdge(src,dest,weight);
    }
      string s;
        cout<<"enter source :";
        cin>>s;
        G.dijkistra(s);
        G.print();
}