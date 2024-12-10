#include<iostream>
using namespace std;
int x[1000];
class stack
{   
    public:
    int top;
    stack()
    {
        top=-1;
    }
    void push(int size)
    {   
        if(top==size-1)
        {
            cout<<"Stack Overflow !!!"<<endl;
            return;
        }
        top++;
        cout<<"Enter the element "<<top+1<<" ::::"<<endl;
        
        cin>>x[top];
    }
    void pop(int size)
    {
        if(top==-1)
        {
            cout<<"No elements entered yet ::::"<<endl;
            return;
        }
        cout<<x[top]<<" is deleted from the stack !!"<<endl;
        top--;
    }
    void display(int size)
    {   
        if(top==-1)
        {
            cout<<"No elements are present !!"<<endl;
        }
        cout<<"Elements present in the stack are ::::"<<endl;
        for(int i=0;i<=top;i++)
        {
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
    
};
int main()
{
    cout<<"Enter the size of the array :::"<<endl;
    int n;
    cin>>n;
    stack obj;
    for(int i=0;i<n;i++)
    {
        obj.push(n);
    }
    obj.display(n);
    cout<<endl<<endl;
    cout<<"Do you want to delete the element from the stack ?(Y/N)"<<endl;
    char ch;
    cin>>ch;
    cout<<endl;
    if(ch=='y' || ch=='Y')
    {   
        cout<<"How many elements you want to delete ?"<<endl;
        int h;
        cin>>h;
        for(int i=0;i<h;i++)
        {
            obj.pop(n);
        }
        obj.display(n);
    }
    else if(ch=='n' || ch=='N')
    {
        return 0;
    }
    else
    {
        cout<<"Wrong entry made ::::"<<endl;
    }

    return 0;


}
