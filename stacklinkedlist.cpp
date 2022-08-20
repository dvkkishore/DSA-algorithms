#include <iostream>

int top=-1;

using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *head,*temp,*ptr;

void push(int n)
{
    if(top==n-1)
    {
        cout<<"Overflow"<<endl;;
    }
    else
    {
        int item;
        cin>>item;
        ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=item;
        if(head==NULL)
        {
            ptr->next=head;
            head=ptr;
            top++;
        }
        else
        {   
            temp=head;
            for(int i=0;i<top;i++)
            {
                temp=temp->next;
            }
            ptr->next=temp->next;
            temp->next=ptr;
            top++;
        }
    }
}

void pop()
{
    temp=head;
    if(top==-1)
    {
        cout<<"Underflow"<<endl;
    }
    else
    {
        if(head==NULL)
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
            if(top==0)
            {
                head=temp->next;
            }
            else
            {
                for(int i=0;i<top;i++)
                {
                    ptr=temp;
                    temp=temp->next;
                }
                ptr->next=temp->next;
            }
            free(temp);
            top--;
        }
    }
}

void display()
{
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

int main()
{
    int n,choice;
    cin>>n;
    head=NULL;
    
    cout<<"0: Exit"<<endl<<"1: Push"<<endl<<"2: Pop"<<endl<<"3: Display"<<endl<<endl;
    do
    {
        cout<<"Choice : ";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
            case 1:
                push(n);
                break;
                
            case 2:
                pop();
                break;
            
            case 3:
                display();
                break;
            }
    }while(choice!=0);
    
    cout<<"Terminated";
}