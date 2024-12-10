#include<iostream>
using namespace std;
int recfib(int);
int main()
{
        int n;
        cout<<"Enter the term of fibonacci series which is to be displayed :::"<<endl;
        cin>>n;
        cout<<recfib(n-1);
        return 0;
}
int recfib(int n)
{
        if(n==0 || n==1)
        {       
                return n;

        }
        return recfib(n-1)+recfib(n-2);
}