#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    int height;
    struct node*left;
    struct node*right;
}node;

int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
int ht(struct node*root)
{
    if(root==NULL)
        return 0;
    else
    {
        return(1+max(ht(root->left),ht(root->right)));
    }
}



struct node *rightrot(struct node*root)
{
    node*y=root->left;
    node*temp=y->right;
    y->right=root;
    root->left=temp;
    root->height=max(ht(root->left),ht(root->right))+1;
    y->height=max(ht(y->left),ht(y->right))+1;
    return y;
}

struct node *leftrot(struct node*root)
{
    node*y=root->right;
    node*temp=y->left;
    y->left=root;
    root->right=temp;
    return y;
}

struct node *create(struct node* root,int data)
{
    if(root==NULL)
    {
    struct node*nn=(node*)malloc(sizeof(node));
    nn->data=data;
    nn->height=1;
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
    int balance = ht(root->left)-ht(root->right);
    if(balance>1)
    {
        if(ht(root->left->left)-ht(root->left->right)>=0)
        {
            return rightrot(root);
        }
        else
        {
            root->left = leftrot(root->left);
            return rightrot(root);
        }
    }
    else if(balance<-1)
    {
        if(ht(root->right->left)-ht(root->right->right)>=0)
        {
            root->right=rightrot(root->right);
            return leftrot(root);
        }
        else
        {
            return leftrot(root);
        }
    }
    else
    {
      root->height = max(ht(root->left),ht(root->right))+1;
      return root;
    }
}

void inorder(struct node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main()
{
    int arr[]={15,20,24,10,13,7,30,36,25};
    int i;
    struct Node *root=NULL;
    for(i=0;i<9;i++)
    {
        root=create(root,arr[i]);
    }
    inorder(root);
}
