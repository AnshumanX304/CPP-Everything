#include<iostream>
using namespace std;
int main()
{
    cout<<"enter upto which term the power of two is to be dispalyed :::"<<endl;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
            cout<<(1<<i)<<endl;

    }
    return 0;
}