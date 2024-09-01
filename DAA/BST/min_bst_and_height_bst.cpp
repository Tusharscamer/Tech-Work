#include<iostream.h>
using namespace std;
struct Build_Bst
{
    int data;
    struct Build_Bst *left;
    struct Build_Bst *right; 
    struct Build_Bst *next;
};

int tree_sum(struct Build_Bst *root){
     if(root==NULL){
        return 0;
     }
      return  root->data+tree_sum(root->left)+tree_sum(root->right);
}
// count number of node
int num_of_node1(struct Build_Bst *root){
    if(root==NULL){
        return 0;
    }
     return 1+num_of_node1(root->left)+num_of_node1(root->right);
    }
// another way tree sum
int tree_sum2(struct Build_Bst *root){
    if(root==NULL){
        return 0;
    }
    int leftsum=tree_sum2(root->left);
    int rightsum=tree_sum2(root->right);
    int sum=root->data+leftsum+rightsum;
    return sum;
}
// min element in Bst
struct Build_Bst *min_element(struct Build_Bst *root){
      if(root->left==NULL){
          return root;
      } 
}
struct Build_Bst *max_element(struct Build_Bst *root){
      if(root->right==NULL){
          return root;
      }
}
// Search element in Bst Iterative way
//  struct Build_Bst *Search_element_Ite(struct Build_Bst *root,int value){
//     while(root!=NULL || root->data!=value){
//         if(root->data>value){
//             root=root->left
//         }
//         else{
//             root=root->right
//         }
//     }
//     return root;
// }
// Search element in Bst Recursive way
// struct Build_Bst *Search_element_Rec(struct Build_Bst *root,int value){
//     if(root==NULL || value==root->data){
//         return root;
//     }
//     else{
//     if(root->data>value){
//             Search_element(root->left,value);
//         }
//     else{
//             Search_element(root->right,value);
//         }
//     }
// }
//recursive inorder traversel
int Rec_Inorder(struct Build_Bst *root){
    if(root!=NULL){
        Rec_Inorder(root->left);
        printf("%d ",root->data);
        Rec_Inorder(root->right);
    }
}
// iterative inorder traversel
int Ite_Inorder(struct Build_Bst *root){
      }
//recursive preorder traversel
int Rec_Preorder(struct Build_Bst *root){
    if(root!=NULL){
        printf("%d ",root->data);
        Rec_Preorder(root->left);
        Rec_Preorder(root->right);
    }
}
//iterative preorder traversel
int Ite_Preorder(struct Build_Bst *root){
     
}
//recursive postorder traversel
int Rec_Postorder(struct Build_Bst *root){
    if(root!=NULL){
        Rec_Postorder(root->left);
        Rec_Postorder(root->right);
        printf("%d ",root->data);
    }
}
//iterative postorder traversel
int Ite_Postorder(struct Build_Bst *root){
}
struct Build_Bst *Build_first_node(int value){
    struct Build_Bst *new_node=(struct Build_Bst*)malloc(sizeof(struct Build_Bst));
    new_node->data=value;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
void Building_Bst(struct Build_Bst *new_node,struct Build_Bst *root){
   if(new_node->data>root->data){
    if(root->right==NULL){
        root->right=new_node;
    }
    else{
        Building_Bst(new_node,root->right);
    }
  }
  else{
    if(root->left==NULL){
        root->left=new_node;
    }
    else{
        Building_Bst(new_node,root->left);
    }
  }  
}
struct Build_Bst *Build_nodes(int value ,struct Build_Bst *root){
    struct Build_Bst *new_node=(struct Build_Bst*)malloc(sizeof(struct Build_Bst));
    new_node->data=value;
    new_node->left=NULL;
    new_node->right=NULL;
    Building_Bst(new_node,root);
}
int main(){
    int no_of_nodes,value;
    printf("enter how many nodes you want in BST :");
    scanf("%d",&no_of_nodes);
    struct Build_Bst *root=(struct Build_Bst*)malloc(sizeof(struct Build_Bst));
    root=NULL;
     for(int i=0;i<no_of_nodes;++i){
         printf("enter the value of nodes no. %d :",i+1);
         scanf("%d",&value);
         if(i==0){
            root=Build_first_node(value);
         }

         else{
            Build_nodes(value,root);
         }

     }
    // creating stack 
    struct stack *head=(struct stack*)malloc(sizeof(struct stack));
    head->next=NULL;
    int operation;
    printf("preoder(1) postorder(2) inorder(3) search_element(4) \n selcet operation :");
    scanf("%d",&operation);
    switch (operation)
    {
    case 1:
    printf("Recursive way(1) Iterative way(2) \n chosse type of execution :");
    scanf("%d",&operation);
    if(operation==1){
        Rec_Preorder(root);
    }
    else{
        Ite_Preorder(root);
    }
    break;

     case 2:
    printf("Recursive way(1) Iterative way(2) \n chosse type of execution :");
    scanf("%d",&operation);
    if(operation==1){
        Rec_Postorder(root);
    }
    else{
        Ite_Postorder(root);
    }
        break;
    
     case 3:
    printf("Recursive way(1) Iterative way(2) \n chosse type of execution :");
    scanf("%d",&operation);
    if(operation==1){
        Rec_Inorder(root);
    }
    else{
        Ite_Inorder(root);
    }
        break;
    case 4:
    printf("element you want to search");
    scanf("%d",&value);
    struct Build_Bst *Searched_element=(struct Build_Bst*)malloc(sizeof(struct Build_Bst));
    // Searched_element=Search_element(root,value);
    if (Searched_element==NULL)
    {
        printf("element not found");
    }
    else{
         printf("%d",Searched_element->data);
    }
    case 5:
    printf("%d",tree_sum2(root));
    value=num_of_node1(root);
    printf("%d",value);
    default:
        break;
    }
}
