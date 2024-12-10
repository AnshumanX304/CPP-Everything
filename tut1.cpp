#include<iostream>
using namespace std;
int main()
{
        int n;
        cin>>n;
        int arr[n+1];
        int rem[n+1];
        for(int i=0;i<=n;i++)
        {
                cin>>arr[i];
        }
        for(int i=0;i<=n;i++)
        {
                rem[i]=arr[i]%3;
        }
        cout<<endl;
        int count[3]={0,0,0};
        for(int i=0;i<=n;i++)
        {
                count[rem[i]]++;
        }
        for(int i=0;i<3;i++)
        {
                cout<<count[i];
        }
        int moves=0;
        int temp;
        for(int i=0;i<2;i++)
        {
                temp=count[i+1]-count[i];
                if(temp<0)
                {
                        temp*=-1;
                }
                moves+=temp;
        }
        cout<<moves<<endl;
        return 0;
}