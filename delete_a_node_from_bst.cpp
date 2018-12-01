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
     cout<<s->data<<" ";
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
int findmax(struct Node*root)
{
    if(root->right)
        root=root->right;
    return root->data;
}
struct Node *del(struct Node* root, int item)
{
    if(root->data==item)
    {
      if(root->left==NULL)
        return root->right;
      else if(root->right==NULL)
        return root->left;
      else
      {
          int x = findmax(root->left);
          root->data=x;
          root->left=del(root->left,root->data);
          return root;
      }
    }
    else
    {
        if(root->data>item)
        {
            root->left=del(root->left,item);
        }
        else if(root->data<item)
        {
            root->right=del(root->right,item);
        }
        return root;
    }
}

int main()
{
    int arr[]={10,15,5,2,12,8,18,1,4,3,16,20};
    int i;
    struct Node *root=NULL;
    for(i=0;i<12;i++)
    {
        root=create(root,arr[i]);
    }
    print(root,12);
    root=del(root,5);
    cout<<endl<<"after deletion"<<endl;
    print(root,12);
}
