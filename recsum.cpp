#include<iostream>
using namespace std;
int recsum(int,int);
int main()
{
    cout<<"Enter the number uptil which the sum of numbers is to be obtained :"<<endl;
    int n;
    cin>>n;
    cout<<recsum(n,0);
    return 0;

}
int recsum(int n,int sum)
{
        if(n==0)
            return sum;
        sum=sum+n;
        return recsum(n-1,sum);
        
}