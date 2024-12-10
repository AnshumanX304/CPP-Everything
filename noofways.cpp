#include<iostream>
using namespace std;
int noofways(int,int);
int main()
{
        cout<<"Enter the number of rows and columns ::::"<<endl;
        int n,m;
        cin>>n>>m;
        cout<<noofways(n,m);
        return 0;

}
int noofways(int n,int m)
{
    if(n==1 || m==1)
        return 1;
     return noofways(n,m-1)+noofways(n-1,m);
}