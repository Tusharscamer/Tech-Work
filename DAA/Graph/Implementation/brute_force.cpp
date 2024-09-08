#include<iostream>
#include<vector>
using namespace std;
class node{
    int data; 
};
class edge{
    node src;
    node dest;
    int weight;
    bool direction;
};
class graph{
     vector<edge> Edge;
     vector<node> Node;
};