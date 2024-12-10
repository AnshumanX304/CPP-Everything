#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    cout<<"Enter the range uptil which the armstrong numbers are to be found :::"<<endl;
    int n;
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {       int c=0;
            int temp=i;
            while(temp!=0)
            {
                temp=temp/10;
                c++;
            }
            temp=i;
            int sum=0;
            while(temp!=0)
            {
                    int a=temp%10;
                    sum=sum+pow(a,c);
                    temp=temp/10;

            }
            if(i==sum)
                cout<<i<<endl;
    }
    return 0;
}