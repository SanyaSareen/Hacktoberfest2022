#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};
 
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
 
    return node;
}
 
void display(Node * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<"  ";
    display(root->left);
    display(root->right);
}

Node * LeftClonetree(Node * root){

    if(root==NULL ){
        return NULL;
    }
    
    Node *ln=LeftClonetree(root->left);
    Node * rn=LeftClonetree(root->right);

    Node * nn=  newNode(root->data);
    nn->left=ln;
    root->left=nn;

    root->right=rn;
    return root;
}


struct Node* constructBST(int preorder[], int start, int end)
{

    if (start > end) {
        return NULL;
    }
 
      struct Node* node = newNode(preorder[start]);
 
    int i;
    for (i = start; i <= end; i++)
    {
        if (preorder[i] > node->data) {
            break;
        }
    }
 
   
    node->left = constructBST(preorder, start + 1, i - 1);
 
  
    node->right = constructBST(preorder, i, end);
 
    
    return node;
}
 
int main(void)
{
   
    int preorder[] = { 15, 10, 8, 12, 20, 16, 25 };
    int n = sizeof(preorder)/sizeof(preorder[0]);
 
   
    struct Node* root = constructBST(preorder, 0, n - 1);
 
   //display(root);
   
   Node * newroot= LeftClonetree(root);
    display(newroot);
    
    return 0;
}
