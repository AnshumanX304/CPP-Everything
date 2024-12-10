#include<iostream>
using namespace std;
void ascdesc(int);
void desc(int);
int main()
{
    cout<<"Enter the number to be dispalyed in the ascending and descending order one by one::::"<<endl;
    int n;
    cin>>n;
    cout<<"In the ascending order :::"<<endl;
    ascdesc(n);
    cout<<endl;
    cout<<"In descending order ::::"<<endl;
    desc(n);
    return 0;
}
void ascdesc(int n)
{
        if(n==0)
            return;
        cout<<n<<" ";
        ascdesc(n-1);
}
void desc(int n)
{
        if(n==0)
            return;
        desc(n-1);
            cout<<n<<" ";
}