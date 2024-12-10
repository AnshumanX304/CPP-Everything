#include<iostream>
using namespace std;
int fib(int);
int main()
{
    cout<<"Enter the serial number of fibonacci sequence you want to be displayed ::;"<<endl;
    int n;
    cin>>n;
    cout<<fib(n-1);
    return 0;
}
int fib(int n)
{
    if(n==0 || n==1)
        return n;
    else 
        return fib(n-1)+fib(n-2);
}