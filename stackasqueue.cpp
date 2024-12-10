#include<iostream>
#include<queue>
using namespace std;
class stacks
{
    public:
    int N;
    stacks()
    {
        N=0;
    }
    queue<int> q1;
    queue<int> q2;
    void push(int val)
    {
        q2.push(val);
        while(!q1.empty())
        {
             q2.push(q1.front());
             q1.pop();
        }
        queue<int> temp=q2;
        q2=q1;
        q1=temp;
        
    }
    void pop()
    {

        q1.pop();

    }
    void display()
    {
        if(q1.empty())
        {
            cout<<"No elements to be displayed ::::"<<endl;
            return;
        }
        queue<int> temp;
        while(!q1.empty())
        {
            cout<<q1.front();
            temp.push(q1.front());
            q1.pop();
        }
        q1=temp;

    }


};
int main()
{
    cout<<"Enter the elements to be displayed in the queue ::::"<<endl;
    int n;
    cin>>n;
    stacks s1;
    s1.N=n;
    cout<<"Enter the elements :::"<<endl;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        s1.push(x);
    }
    cout<<"Entered elements are :::"<<endl;
    s1.display();
    cout<<endl;
    s1.pop();
    s1.display();
    return 0;



}