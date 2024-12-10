#include<iostream>
using namespace std;
int stairs(int);
int main()
{
        cout<<"Enter the number of stairs in the staircase ::::"<<endl;
        int n;
        cin>>n;
        cout<<stairs(n);
        return 0;
}
int stairs(int n)
{
        if(n<0)
            return 0;
        if(n==0)
            return 1;
        return stairs(n-1)+stairs(n-2)+stairs(n-3);
}