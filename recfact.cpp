#include<iostream>
using namespace std;
int recfact(int);
int main()
{
        int n;
        cout<<"Enter the number whose factorial is to be found ::::"<<endl;
        cin>>n;
        cout<<recfact(n);
        return 0;
}
int recfact(int n)
{
        if(n==0 )
        {
                return 1;
        }
        int factorial=recfact(n-1);
        return factorial*n;
}