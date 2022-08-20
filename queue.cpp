#include <iostream>

int front=-1,rear=-1;

using namespace std;

void enqueue(int n, int arr[])
{
    int ele;
    
    if(rear==n-1)
    {
        cout<<"Overflow"<<endl;
    }
    else
    {
        
        if(front==-1 && rear==-1)
        {
            front++;
            rear++;
        }
        else
        {
            rear++;
        }
        cin>>ele;
        arr[rear]=ele;
    }
}

void dequeue(int n, int arr[])
{
    if(front==-1)
    {
        cout<<"Underflow"<<endl;
    }
    else
    {
        
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front++;
        }
    }
}

void display(int arr[])
{
    int i;
    if(rear==-1)
    {
        return;
    }
    for(i=front;i<=rear;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    
    int choice;
    
    cout<<"0: Exit\n"<<"1: Insert\n"<<"2: Delete\n"<<"3: Display\n";
    
    do{
        cout<<"Choice: ";
        cin>>choice;
        cout<<endl;
        
        switch(choice)
        {
            case 1:
                {
                    enqueue(n, arr);
                    break;
                }
            case 2:
                {
                    dequeue(n, arr);
                    break;
                }
            case 3:
                {
                    display(arr);
                    break;
                }
        }
    }while(choice!=0);
    
    cout<<"Terminated...";
    return 0;
}