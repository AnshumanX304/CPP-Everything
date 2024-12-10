#include<iostream>
using namespace std;
int sumrec(int);
int main()
{
    cout<<"enter the number uptil which the sum is to be found ::::"<<endl;
    int n;
    cin>>n;
    cout<<sumrec(n);
    return 0;

}
int sumrec(int n)
{
        if(n==0)
            return 0;

        return n + sumrec(n-1);
        
}