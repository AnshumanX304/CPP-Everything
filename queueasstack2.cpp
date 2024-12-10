#include<iostream>
#include<stack>
using namespace std;
class queue2
{
    public:
    void push(stack<int> &st,int val)      
    {
        st.push(val);
    }
    void display(stack<int>st)
    {
        if(st.empty())
        {
            cout<<"No elements to be displayed !!"<<endl;
            return ;
        }
        while(!st.empty())
        {
            cout<<st.top();
            st.pop();
        }
    }
    void pop(stack<int> &st)
    {
        if(st.empty())
        {
            cout<<"No element to pop :::"<<endl;
            return ;
        }
        int val=st.top();
        st.pop();
        if(st.empty())
        {
            return;
        }
        pop(st);
        st.push(val);
        
    }

};
int main()
{
    cout<<"Enter the number of values you want to enter in the queue :::"<<endl;
    int n;
    cin>>n;
    stack<int> st;
    cout<<"Enter the values ::::"<<endl;
    int x;
    queue2 obj;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        obj.push(st,x);
    }
    cout<<"Entered elements in the queue are :::"<<endl;
    obj.display(st);
    cout<<endl;
    obj.pop(st);
    cout<<"Stack after deletion is :::"<<endl;
    obj.display(st);
    return 0;
}