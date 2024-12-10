#include<iostream>
using namespace std;
int main()
{ 
        cout<<"Enter the number whose prime factorisation is to be found :::"<<endl;
        int n;
        cin>>n;
        int x[n+1];
        for(int i=1;i<=n;i++)
        {
                x[i]=i;
        }
        for(int i=2;i<=n;i++)
        {
                if(x[i]==i)
                {
                        for(int j=i*i;j<=n;j+=i)
                        {   
                            if(x[j]==j)
                                x[j]=i;
                        }
                }
        }
        cout<<"Prime factorisation of the entered number is :::"<<endl;
        while(n!=1)
        {
                cout<<x[n]<<" ";
                n=n/x[n];
        }
        return 0;
}
