#include<iostream>
using namespace std;
int recpower(int,int);
int main()
{
    int n,p;
    cout<<"Enter the number :::"<<endl;
    cin>>n;
    cout<<"Enter the power :::"<<endl;
    cin>>p;
    cout<<recpower(n,p);
    return 0;

}
int recpower(int n,int p)
{
        if(p==0)
            return 1;
        int s=recpower(n,p-1);
        return(n*s);

}