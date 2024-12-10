#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the number of elements in the array :::"<<endl;
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the elements :::"<<endl;
    for(int i=0;i<n;i++)
        cin>>a[i];
    bool pivot=1;
    for(int i=0;i<n;i++)
    {
        int sum1=0;
        for(int j=0;j<=i;j++)
        {
            sum1+=a[j];
        }
        int sum2=0;
        for(int k=i;k<n;k++)
        {
            sum2+=a[k];
        }
        if(sum1==sum2)
        {
            cout<<"Pivot is "<<i<<endl;
            pivot=0;
        }

    }
    if(pivot==1)
    {
        cout<<"No pivot element present "<<endl;
    }
    return 0;
}