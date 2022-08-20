#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *left,*right;
};

struct node *root;

int height(node* root)
{
    int h=0;
    if(root!=NULL)
    {
        int l_height=height(root->left);
        int r_height=height(root->right);
        
        h=max(l_height,r_height)+1;
    }
    return h;
}

int difference(node* root)
{
    int l_height=height(root->left);
    int r_height=height(root->right);
    
    int bal = l_height - r_height;
    return bal;
}

node* ll_rotate(node* parent)
{
    node* t;
    t=parent->left;
    parent->left=t->right;
    t->right=parent;
    
    cout<<"Left Left Rotation"<<endl;
    return t;
}

node* rr_rotate(node* parent)
{
    node *t;
    t=parent->right;
    parent->right=t->left;
    t->left=parent;
    
    cout<<"Right Right Rotation"<<endl;
    return t;
}

node* lr_rotate(node* parent)
{
    node* t;
    t=parent->left;
    parent->left=rr_rotate(t);
    cout<<"Left Right Rotation"<<endl;
    return ll_rotate(parent);
}

node* rl_rotate(node* parent)
{
    node* t;
    t=parent->right;
    parent->right=ll_rotate(t);
    cout<<"Right Left Rotation"<<endl;
    return rr_rotate(parent);
}

node* balance(node* root)
{
    int bal_fac=difference(root);
    
    if(bal_fac>1)
    {
        if(difference(root->left)>0)
        {
            root=ll_rotate(root);
        }
        else
        {
            root=lr_rotate(root);
        }
    }
    else if(bal_fac<-1)
    {
        if(difference(root->right)<0)
        {
            root=rr_rotate(root);
        }
        else
        {
            root=rl_rotate(root);
        }
    }
    
    return root;
}

struct node *create(int data)
{
    struct node *Node;
    Node=(struct node *)malloc(sizeof(struct node));
    
    Node->data=data;
    Node->left=NULL;
    Node->right=NULL;
    
    return Node;
}

void inorder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

struct node* insert(struct node* root, int data)
{
    if(root==NULL)
    {
        return create(data);
    }
    
    if(data<root->data)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    
    root=balance(root);
    return root;
}

int main()
{
    struct node *root=NULL;
    int choice;
    
    cout<<"0: Exit\n1: Insert\n2: Inorder\n";
    
    while(choice!=0)
    {
        cout<<endl<<"Choice: ";
        cin>>choice;
        cout<<endl;
        
        switch(choice)
        {
            case 0:
                {
                    cout<<"Terminated..."<<endl;
                    return 0;
                    break;
                }
                
            case 1:
                {
                    int data;
                    cin>>data;
                    root=insert(root, data);
                    break;
                }
                
            case 2:
                {
                    inorder(root);
                    cout<<endl;
                    break;
                }
        }
    }
    
    return 0;
}
