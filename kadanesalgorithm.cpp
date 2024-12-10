#include<iostream>
using namespace std;
int main()
{
        cout<<"enter the size of the array ::"<<endl;
        int n;
        cin>>n;
        int x[n];
        for(int i=0;i<n;i++)
            cin>>x[i];
        int maxsum=INT32_MIN;
        int currentsum=0;
        for(int i=0;i<n;i++)
        {       currentsum=currentsum+x[i];
                if(currentsum<0)
                    currentsum=0;

                maxsum=max(maxsum,currentsum);

        }
        cout<<"longest arithmetic subarray is ::::"<<endl;
        cout<<maxsum;
        return 0;
}