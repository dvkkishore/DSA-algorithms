#include <stdlib.h>
#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head,*ptr,*temp;

void insert(int pos)
{
    int item;
    cin>>item;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=item;
    if(head==NULL || pos==0)
    {
        ptr->next=head;
        head=ptr;
    }
    else
    {
        temp=head;
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        
        ptr->next=temp->next;
        temp->next=ptr;
    }
}

void deletion()
{
    int pos,i;
    cin>>pos;
    temp=head;
    
    if(pos-1==0)
    {
        head=temp->next;
    }
    else
    {
        for(i=0;i<pos-1;i++)
        {
            ptr=temp;
            temp=temp->next;
        }
        ptr->next=temp->next;
    }
    free(temp);
}
void display()
{
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        cout<<endl;
        ptr=ptr->next;
    }
}

int main()
{
    int choice,i,pos;
    
    choice=10;
    head=NULL;
    i=0;
    
    cout<<"0: Exit."<<endl<<"1: Display"<<endl<<"2: Insert continuous."<<endl<<"3: Insert Random."<<endl<<"4: Deletion"<<endl;
    while(choice!=0)
    {
        cout<<"Choice:"<<" ";
        cin>>choice;
        switch(choice)
        {
            case 0:
                cout<<"Terminated";
                return 0;
            case 2:
                insert(i);
                i++;
                break;
            case 1:
                display();
                break;
            case 3:
                cin>>pos;
                insert(pos-1);
                break;
            case 4:
                deletion();
        }
    }
    
    return 0;
}