#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the value of n::::"<<endl;
    int n;
    cin>>n;
    int a[n]={0};
    cout<<"Enter the marks ::::"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]>38)
        {
            if(a[i]%5>3)
            {
                a[i]=((a[i]/5)+1)*5;
            }
        }
    }
    cout<<"Changed marks are :::"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
