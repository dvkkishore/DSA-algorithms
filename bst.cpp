#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *left,*right;
};
struct node *root;

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
    return root;
}

void search(struct node* &cur, struct node* &parent, int data)
{
    while(cur!=NULL && cur->data!=data)
    {
        parent=cur;
        if(data<cur->data)
        {
            cur=cur->left;
        }
        else
        {
            cur=cur->right;
        }
    }
}

node* findMinimum(struct node* cur)
{
    while(cur->left!=NULL)
    {
        cur=cur->left;
    }
    return cur;
}

void deletion(struct node* &root, int data)
{
    struct node* parent=NULL;
    struct node* cur=root;
    
    search(cur,parent,data);
    
    if(cur==NULL)
    {
        return;
    }
    
    if(cur->left==NULL && cur->right==NULL)
    {
        if(cur!=root)
        {
            if(parent->left==cur)
            {
                parent->left=NULL;
            }
            else
            {
                parent->right=NULL;
            }
        }
        else
        {
            root=NULL;
        }
        free(cur);
    }
    else if(cur->left&&cur->right)
    {
        node* succ=findMinimum(cur->right);
        int val=succ->data;
        deletion(root,val);
        cur->data=val;
    }
    else
    {
        struct node* child=(cur->left)?cur->left:cur->right;
        
        if(cur!=root)
        {
            if(parent->left==cur)
            {
                parent->left=child;
            }
            else
            {
                parent->right=child;
            }
        }
        else
        {
            root=child;
        }
        free(cur);
    }
}

int main()
{
    struct node *root=NULL;
    int choice;
    
    cout<<"0: Exit\n1: Insert\n2: Delete\n3: Inorder\n";
    
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
                    int data;
                    cin>>data;
                    deletion(root,data);
                    break;
                }
                
            case 3:
                {
                    inorder(root);
                    cout<<endl;
                    break;
                }
        }
    }
    
    return 0;
}