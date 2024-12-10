#include<iostream>
#include<stack>
using namespace std;
void insertatbottom(stack<int> &a,int ele)
{
    if(a.empty())
    {
        a.push(ele);
        return;
    }
    int topele=a.top();
    a.pop();
    insertatbottom(a,ele);
    a.push(topele);
}
void reverse(stack<int> &a)
{
    if(a.empty())
    {
        return;
    }
    int ele=a.top();
    a.pop();
    reverse(a);
    insertatbottom(a,ele);


}
void push(stack<int> &a,int n)
{   int x;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the element "<<i+1<<" :::::"<<endl;
        cin>>x;
        a.push(x);
    }
    reverse(a);
}


int main()
{
    cout<<"Enter the number of elements you want to enter in the stack ::::"<<endl;
    int n;
    cin>>n;
    stack<int> a;
    push(a,n);
    cout<<"Afer reversal the stack becomes :::"<<endl;
    while(!a.empty())
    {
        cout<<a.top()<<" ";
        a.pop();
    }
    return 0;
}