#include <iostream>

int top=-1;

using namespace std;

void push(int n, int arr[])
{
    if(top==n-1)
    {
        cout<<"Overflow"<<endl;
        return;
    }
    else
    {
        top++;
        int item;
        cin>>item;
        arr[top]=item;
        return;
    }
}

void pop(int arr[])
{
    if(top==-1)
    {
        cout<<"Underflow"<<endl;
    }
    else
    {
        cout<<"Element "<<arr[top]<<endl;
        top--;
    }
}

void display(int arr[])
{
    for(int i=0;i<=top;i++)
    {
        cout<<arr[i]<<" "<<endl;
    }
}

int main()
{
    int n,choice=10;
    cin>>n;
    
    int arr[n];
    
    while(choice!=0)
    {
        cout<<"Choice : ";
        cin>>choice;
        switch(choice)
        {
            case 0:
                cout<<"Terminated";
                return 0;
                
            case 1:
                push(n,arr);
                break;
            
            case 2:
                pop(arr);
                break;
            
            case 3:
                display(arr);
                break;
        }
    }

    return 0;
}