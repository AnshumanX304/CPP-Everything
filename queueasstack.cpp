#include<iostream>
#include<stack>
using namespace std;
class queu
{
    public:
    stack<int> st1;
    stack<int> st2;
    void push(int x)
    {
        st1.push(x);
    }
    void pop()
    {
        if(st1.empty() && st2.empty())
        {
            cout<<"Queue is empty !"<<endl;
            return;
        }

        if(st2.empty())
        {   
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
           
            st2.pop();

            
        }
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }
    void display()
    {
        if(st1.empty() && st2.empty())
        {
            cout<<"Sab khali hai"<<endl;
        }
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        while(!st2.empty())
        {
            cout<<st2.top()<<" ";
            st1.push(st2.top());
            st2.pop();
        }
    }
    void peek()
    {
        if(st1.empty())
            cout<<"No elements present !"<<endl;
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        cout<<endl;
        cout<<"The first element in the queue is :::"<<endl;
        cout<<st2.top();
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
    }

};
int main()
{
    cout<<"Enter the number of elements you want to enter in the queue ::::"<<endl;
    int n;
    cin>>n;
    queu obj;
    cout<<"Enter the elements :::"<<endl;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        obj.push(x);
    }
    cout<<"Entered elements are :::"<<endl;
    obj.display();
    cout<<endl;
    cout<<"Do you want to delete the element from the queue ?"<<endl;
    char ch;
    cin>>ch;
    if(ch=='y'|| ch=='Y')
    {
        obj.pop();
    }
    else if(ch=='n'||ch=='N')
    {
        return 0;
    }
    else
        cout<<"Fuck off !!"<<endl;

    cout<<endl;
    cout<<"Queue after deletion is :::"<<endl;
    obj.display();
    obj.peek();
    return 0;
}