#include<iostream>
using namespace std;
int x[1000];
class queue
{   public:
    int front;          //to store the address of the first element
    int back;           //to store the address of the latest entered element
    queue()
    {
        front=-1;
        back=-1;
    }
    void push(int val)          //to enter the element in the queue
    {
        if(front=-1)
        {
            front++;
            back++;
            x[back]=val;
            return ;
        }
        back++;
        x[back]=val;

    }
    void pop()                  //to remove the element in the queue
    {
        if(front==-1 || front>back)
        {
            cout<<"Queue underflow !!!"<<endl;
            return;
        }
        front ++;

    }
    void peek()                 //to find the first element in the queue
    {
        if(front==-1 ||front>back)
        {
            cout<<"No elements are present in the queue "<<endl;
            return ;
        }
        cout<<x[front];
    }
    void display()              //to display all elements in the queue
    {
        if(front==-1 || front>back)
        {
            cout<<"Queue underflow !!!"<<endl;
            return;
        }
        for(int i=front;i<=back;i++)
        {
            cout<<x[i]<<" ";
        }
    }
};
int main()
{
    cout<<"Enter the size of the array ::::"<<endl;
    int n;
    queue obj;
    cin>>n;
    cout<<"Enter the elements :::"<<endl;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        obj.push(x);

    }
    cout<<"Entered elements are ::::"<<endl;
    obj.display();
    cout<<endl;
    cout<<"Do you want to delete the element in the queue ?(y/n)"<<endl;
    char ch;
    cin>>ch;
    if(ch=='y' || ch=='Y')
    {
        obj.pop();
    }
    else if(ch=='n' || ch=='N')
    {
        return 0;
    }
    else    cout<<"Fuck off"<<endl;
    cout<<"List after deletion is :::"<<endl;
    obj.display();
    cout<<endl;
    cout<<"The first element in the queue is ::::"<<endl;
    obj.peek();
    return 0;
}
