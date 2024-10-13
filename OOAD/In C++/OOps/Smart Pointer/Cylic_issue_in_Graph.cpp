#include<bits/stdc++.h>
using namespace std;
class Node{
    private:
    string label;
    vector<weak_ptr<Node>>adjlist;
    public: 
    Node(){
        
    }
    Node(string y){
     label=y;
    }
    void addVertex(shared_ptr<Node>w){
       adjlist.push_back(w);
    }
    void display(){
       cout<<"Nodes adjacent to our Node"<<label<<":\n";
       for(int i=0;i<adjlist.size();i++){
             cout<<(adjlist[i]).lock()->label;
      }
    }
    friend class graph;
     ~Node(){
       cout<<"\n destructor called";
     }
};
class Graph{
    public:
    vector<shared_ptr<Node>> g;
    void addNode(shared_ptr<Node>node){
        g.push_back(node);
    }
    void displaygraph(){
       for(int i=0;i<g.size();i++){
            g[i]->display();
            cout<<endl;
       }
    }
    void addedge(shared_ptr<Node>Node1,shared_ptr<Node>Node2){
       Node1->addVertex(Node2);
       Node2->addVertex(Node1);
    }
};
int main(){
     shared_ptr<Node> n1=make_shared<Node>("a");
     shared_ptr<Node> n2=make_shared<Node>("b");
      n2->addVertex(n1);
      n1->addVertex(n1);
      n2->display();
      Graph g1;
      g1.addNode(n1);
      g1.addNode(n2);
      g1.displaygraph();
}