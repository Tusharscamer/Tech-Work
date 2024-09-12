#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
class tree{
    public:
    int data;
    tree *left;
    tree *right;
    tree();  
    tree(int val ){
        left=NULL;
        right=NULL;
        data=val;
    }
};
void Build_bst(vector<int> arr,tree *root){
     queue <tree*> q;
     q.push(root);
     int i=1;
     while(i<arr.size()){
        tree* curr=q.front();
        q.pop();
        if(i<arr.size()){
           curr->left= new tree(arr[i]);
           q.push(curr->left);
           ++i;
        }
        if(i<arr.size()){
            curr->right= new tree(arr[i]);
            ++i;
            q.push(curr->right);
        }
     }
}
void inorder(tree* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int main(){
    int n;
    cout<<"no of nodes :";
    cin>>n;
    int val;
    vector<int> arr;
    for(int i=0;i<n;++i){
        cin>>val;
        arr.push_back(val);
    }
    tree *root= new tree(arr[0]);
    Build_bst(arr,root);
    inorder(root);
}