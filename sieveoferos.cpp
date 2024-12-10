#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the upper limit until which the range is to be found "<<endl;
    int n;
    cin>>n;
    int x[n];
    for(int i=1;i<=n;i++)
    {
        x[i]=1;
    }
    for(int i=2;i<=n;i++)
    {   if(i*i<=n)
        {
            for(int j=i*i;j<=n;j=j+i)
            {   
                if(x[j]==1)
                {    
                    x[j]=0;
                }
            }
         }
    }
    for(int i=2;i<=n;i++)
    {
            if(x[i]==1)
                cout<<i<<endl;
    }
    return 0;
}
