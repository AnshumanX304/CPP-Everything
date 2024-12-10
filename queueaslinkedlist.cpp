//same program as stack as linked list with the difference being that here 
//two pinters are used instead of one.
#include<iostream>
using namespace std;
class node
{   public:
    int a;
    node *next;
    node(int val)
    {
        a=val;
        next=NULL;
    }
    node()
    {
        next=NULL;
    }
};
class queue
{
    public:
    node *front;
    node* back;
    queue()
    {
        front=NULL;
        back=NULL;
    }
    void push(int val)
    {
        node *n=new node(val);
        if(front==NULL)
        {
            front=n;
            back=n;
            return;
        }
        back->next=n;
        back=n;

    }
    void display()
    {
        if(front==NULL)
        {
            cout<<"No elements to be displayed"<<endl;
            return ;
        }
        node*tfront=front;      //temporary pointer should be used so that 
        node*tback=back;        //the original value of front and back are not disturbed
        while(tfront!=tback)
        {
            cout<<tfront->a<<" ";
            tfront=tfront->next;
        }
        cout<<tfront->a<<endl;
    }
    void pop()
    {
        if(front==NULL)
        {
            cout<<"Sab pehle hi khali hai :::"<<endl;
            return;
        }
        node*todelete=front;
        front=front->next;
        delete todelete;
    }
    void peek()
    {
        if(front==NULL)
        {
            cout<<"No element is present in the queue !"<<endl;
            return;
        }
        cout<<"The first element in the queue is :::"<<endl;
        cout<<front->a<<endl;

    }
    bool empty()
    {
        if(front==NULL)
        {
            return 1;
        }
        return 0;
    }
};
int main()
{
    cout<<"Enter the number of elements you want to enter in the queue::::"<<endl;
    int n;
    cin>>n;
    int x;
    queue obj;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        obj.push(x);
    }
    cout<<"Entered elements are :::"<<endl;
    obj.display();
    cout<<"Do you want to delete the elements (y/n) ?"<<endl;
    char ch;
    cin>>ch;
    if(ch=='y' || ch=='Y')
    {
        cout<<"How many elements you want to be deleted ?"<<endl;
        cin>>n;
        for(int i=0;i<n;i++)
            obj.pop();
    }
    else if(ch=='N' || ch=='n')
    {
        return 0;
    }
    else
    {
        cout<<"fuck off !!"<<endl;
    }
    cout<<"Queue after deletion is :::"<<endl;
    obj.display();
    obj.peek();
    if(obj.empty())
    {
        cout<<"No Elements are there in the list"<<endl;

    }
    else{
        cout<<"Elements are present"<<endl;
    }
    return 0;
}