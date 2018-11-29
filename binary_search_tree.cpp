#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newnode()
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    return newnode;
};
struct Node *create(struct Node* root,int data)
{
    if(root==NULL)
    {
    struct Node*nn=newnode();
    nn->data=data;
    nn->left=NULL;
    nn->right=NULL;
    return nn;
    }
    if(data > root->data)
    {
        root->right=create(root->right,data);
    }
    else if(data < root->data)
    {
        root->left=create(root->left,data);
    }
    return root;
}

void print(struct Node*root,int n)
{
 queue <struct Node*> q;
 q.push(root);
 while(!q.empty())
 {
     struct Node *s=q.front();
     cout<<s->data;
     q.pop();
     if(s->left)
     {
         q.push(s->left);
     }
     if(s->right)
     {
         q.push(s->right);
     }
 }
}
int main()
{
    int arr[]={5,7,2,9,3,4,8,13};
    int i;
    struct Node *root=NULL;
    for(i=0;i<8;i++)
    {
        root=create(root,arr[i]);
    }
    print(root,8);
}
