#include<iostream>
using namespace std;
struct Build_Bst{
    int data;
    struct Build_Bst *left;
    struct Build_Bst *right;
};
int contructing_tree(struct Build_Bst *root,struct Build_Bst *node){
    if(root==NULL){
        root=node;    
    }
    else{
        if(root->data>node->data){
            contructing_tree(root->left,node);
        }
        else{
            contructing_tree(root->right,node);
        }
        }
    }
struct Build_Bst *ite_lowest_common_ancestor(struct Build_Bst *root,int node1 ,int node2){
    while(root!=NULL){
        if(root->data>node1 && root->data>node2){
            root=root->left;
        }
        else if(root->data<node1 && root->data<node2){
            root=root->right;
        }
        else{
            break;
        }
    }
    return root;
}
// LCA in Recursive way
struct Build_Bst * rec_lowest_common_ancestor(struct Build_Bst *root,int node1,int node2){
    if(root==NULL){
        return NULL;
    }
    if(root->data<node1 && root->data>node2){
        rec_lowest_common_ancestor(root->left,node1,node2);
    }
    if(root->data<node1 && root->data<node2){
        rec_lowest_common_ancestor(root->right,node1,node2);
    }
    return root;
}
int main(){
    int no_of_nodes,value_node,value_root;
    cout<<"Enter the number of nodes you want to enter"
    ;
    cin>>no_of_nodes;
    cout<<"Enter the value of root";
    cin>>value_root;
    struct Build_Bst *root= new Build_Bst;
    root->data=value_root;
    root->left=NULL;
    root->right=NULL;
    for(int i=0;i<no_of_nodes;++i){
        cout<<"Enter the value of node";
        cin>>value_node;
        struct Build_Bst *node= new Build_Bst;
        node->data=value_node;
        node->left=NULL;
        node->right=NULL;
        contructing_tree(root,node);
    }
    int node1,node2;
    cout<<"Enter the value of two nodes";
    cin>>node1>>node2;
    struct Build_Bst *lca= lowest_common_ancestor(root,node1,node2);
    cout<<"The lowest common ancestor of the given nodes is"<<lca->data;
}