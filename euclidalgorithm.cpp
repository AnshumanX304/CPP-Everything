#include<iostream>
using namespace std;
int main()
{
    cout<<"enter the two numbers to find the hcf :::::"<<endl;
    int a,b;
    cin>>a>>b;
    while(b!=0)
    {
            int r=a%b;
            a=b;
            b=r;
            
    }
    cout<<"HCF of the given numbers is :::"<<endl;
    cout<<a;
    return 0;
}