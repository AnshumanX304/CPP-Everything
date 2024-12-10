#include<iostream>
#include<math.h>

using namespace std;
int main()
{
        cout<<"enter the upper limit of the range in which you want to find the armstrong number ::::"<<endl;
        int n;
        cin>>n;
        int sum;
        int a;
        cout<<"Armstrong numbers in given range are :::"<<endl;
        for(int i=1;i<=n;i++)
        {   int temp=i;
            sum=0;
            while(temp>0)
            {
                a=temp%10;
                temp=temp/10;
                sum=sum+pow(a,3);
            }
            if(sum==i)
            {
                cout<<sum<<endl;
            }
        }
        return 0;
}