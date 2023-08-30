#include<bits/stdc++.h>

using namespace std;

class node{
 public:
  int data;
  node *left,*right;
};

int height(node* root)
{
    if(root == NULL)
    return 0;
    else {
        int lheight=height(root->left);
        int rheight=height(root->right);
        if(lheight>rheight)
        return lheight+1;
        else
        return rheight+1;
    }
}

void printcurrentLevel(node* root,int level)
{
    if(level==0)
    return;
    else if(level==1)
    cout<<root->data<<" ";
    else{
        printcurrentLevel(root->left,level-1);
        printcurrentLevel(root->right,level-1);
    }
 
}
void printlevelorder(node *root)
{
    int h=height(root);
    for(int i=1;i<=h;i++)
    printcurrentLevel(root,i);
}

node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return (Node);
}

int main(){
    node* root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(4);
    root->left->left = newNode(1);
    root->left->right = newNode(5);
    cout << "Level Order traversal of binary tree is \n";
    printlevelorder(root);
    return 0;
}