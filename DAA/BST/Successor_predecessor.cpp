#include <iostream>
using namespace std;
struct Build_Bst{
    public:
    int data;
    struct Build_Bst *left;
    struct Build_Bst *right;
    struct Build_Bst *parent; 
};
int count_leaf(struct Build_Bst *root){
   if(root == NULL)     
        return 0; 
    if(root->left == NULL && root->right == NULL) 
        return 1;         
    else
        return count_leaf(root->left)+ 
            count_leaf(root->right); 
} 

// print node at that level
void print_level(struct Build_Bst *root,int level ,int current_level){
    if(root!=NULL){
        if(current_level==level){
            cout<<root->data<<" ";
        }
        print_level(root->left,level,current_level+1);
        print_level(root->right,level,current_level+1);
    }
}
// level in Tree
int find_level(struct Build_Bst *root){
    if(root==NULL){
        return 0;
    }
    return 1+max(find_level(root->left),find_level(root->right));
}
// find max node in Tree not in BST
int max_tree(struct Build_Bst *root){
    if(root==NULL){
        return -1;
    }
    return max(root->data,max(max_tree(root->right),max_tree(root->left)));
}
struct Build_Bst *search_element(struct Build_Bst *root,int value){
    if(root==NULL || root->data==value){
        return root;
    }
    else{
        if(root->data>value){
            search_element(root->left,value);
        }
        else{
            search_element(root->right,value);
        }
    }
}
// same for both
struct Build_Bst *min_find(struct Build_Bst *node){
    while(node->left!=NULL){
        node=node->left;
    }
    return node;
}
// method 2
struct Build_Bst *successor_find_m2(struct Build_Bst *node,struct Build_Bst *root){

    if(node->right!=NULL){
        return min_find(node->right);
    }
   struct Build_Bst *succ=new Build_Bst;
   while(root!=NULL){
      if(root->data>node->data){
        succ=root;
        root=root->left;
      }
      else{
        succ=root;
        root=root->right;
      }
      return succ;
   }
}
// method 1
struct Build_Bst *successor_find_m1(struct Build_Bst *node){
     if(node->right==NULL){
        return  min_find(node->right);
     }
     struct Build_Bst *parent= new Build_Bst;
     parent=node->parent;
     while(parent->right==node && parent!=NULL){
        node=parent;
        parent=node->parent;
     }
     return parent;
}
struct Build_Bst contruct_Bst(struct Build_Bst *node,struct Build_Bst *root){
    
    if(root->data>node->data){
        if(root->left==NULL){
            root->left=node;
            node->parent=root;
        }
        else{
            contruct_Bst(node,root->left);
        }
    }
    else{
        if(root->right==NULL){
            root->right=node;
            node->parent=root;
        }
        else{
            contruct_Bst(node,root->right);
        }
    }
}
struct Build_Bst *Build_nodes(int value){
    struct Build_Bst *new_node = new Build_Bst;
    new_node->data = value;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = NULL;
    return new_node;
}
int main(){
    int no_of_nodes,value_node,value_root,manual,manual1;
    cout<<"enter value of root ";
    cin>>value_root;
    cout<<"enter how many nodes you want in tree";
    cin>>no_of_nodes;
    struct Build_Bst *root = new Build_Bst;
    root->data = value_root;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
    struct Build_Bst *restore= root;
    struct Build_Bst *node= new Build_Bst;
    for(int i=0;i<no_of_nodes;++i){
        cout<<"enter the value of node :";
        cin>>value_node;
        node=Build_nodes(value_node);
        root=restore;
        contruct_Bst(node,root);
    }
    cout<<"successor_of_node(1) predeccessor_of_node(2) max_tree(3):";
    cin>>manual;
    switch (manual)
    {
    case 1:
        cout<<"enter vlaue of node";
        cin>>value_node;
        restore=root;
        node= search_element(root,value_node);
        cout<<"method 1/2";
        cin>>manual1;
        switch (manual1)
        {
        case 1:
        node=successor_find_m1(node);
        cout<<node->data;
        break;
        case 2:
        node=successor_find_m2(node,root);
        cout<<node->data;
       
        default:
            break;
        }
    break;
    case 3:
         cout<<max_tree(root);
         break;
    case 4:
        cout<<find_level(root);
        break;
    case 5:
        cout<<"specify level";
        cin>>value_node;
        print_level(root,value_node,0);
        break;
    case 6:
         value_node=count_leaf(root);
        cout<<value_node;
        break;
    default:
     cout<<"invalid input";  
     break;
    }
}