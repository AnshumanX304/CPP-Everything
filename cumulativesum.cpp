#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the size of the array :::"<<endl;
    int n;
    cin>>n;
    int x[n];
    cout<<"Enter the elements ::::"<<endl;
    for(int i=0;i<n;i++)
    {
            cin>>x[i];
    }
    int currsum[n+1];
    currsum[0]=0;
    for(int i=1;i<=n;i++)
    {
        currsum[i]=currsum[i-1]+x[i-1];
    }
    int maxsum=INT64_MIN;
    for(int i=0;i<=n;i++)
    {   int sum=0;
        for(int j=0;j<i;j++)
        {
            sum=currsum[i]-currsum[j];
            maxsum=max(sum,maxsum);


        }
    }
    cout<<"largest subarray sum is :::"<<endl;
    cout<<maxsum<<endl;
    return 0;
       
}