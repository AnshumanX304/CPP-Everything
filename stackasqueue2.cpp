#include<iostream>
#include<queue>
using namespace std;
class stacks
{
    queue<int> q1;
    queue<int> q2;
    int N;
    public:
    stacks()
    {
        N=0;
    }
    void push(int val)
    {
        q1.push(val);
    }
    void pop()
    {
        if(q1.empty())
        {
            cout<<"The stack is empty!"<<endl;
            return;
        }
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        queue<int> temp=q2;
        q2=q1;
        q1=temp;

    }
    void display()
    {
        queue<int>temp=q1;
        while(!temp.empty())
        {
            cout<<temp.front();
            temp.pop();
        }
    }



};
int main()
{
    cout<<"Enter the number of elements to be entered in the queue :::"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the elemeents in the queue ::::"<<endl;
    int x;
    stacks s;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        s.push(x);
    }
    cout<<"Entered elements are :::"<<endl;
    s.display();
    s.pop();
    cout<<endl;
    cout<<"Stack after deletion is ::::"<<endl;
    s.display();
    return 0;
}