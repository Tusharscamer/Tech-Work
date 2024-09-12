#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class tree{
    public:
    int data;
    tree* left;
    tree* right;
    tree(int val){
        left=NULL;
        right=NULL;
        data=val;
    }
};
void inorder(tree* root){
     stack<tree*> s;
     while(!s.empty() || root!=NULL){
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }
        root=s.top();
        cout<<root->data<<" ";
        s.pop();
         root=root->right;
     }
}
void Build_bt(vector<int> arr,tree* root){
    queue<tree*>q;
    q.push(root);
    int i=1;
    while(i<arr.size()){
        tree* curr=q.front();
        q.pop();
        if(i<arr.size()){
            curr->left=new tree(arr[i]);
            q.push(curr->left);
            ++i;
        }
        if(i<arr.size()){
            curr->right=new tree(arr[i]);
            q.push(curr->right);
            ++i;
        }
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
    Build_bt(arr,root);
    inorder(root);
}
