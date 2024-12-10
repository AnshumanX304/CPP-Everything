#include<iostream>
using namespace std;
int sorted(int[],int,int);
int main()
{
    cout<<"Enter the size of the array :::"<<endl;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
            cin>>arr[i];
    }
    bool flag=sorted(arr,n,0);
    if(flag==0)
        cout<<"array is unsorted"<<endl;
    else
        cout<<"array is sorted "<<endl;
    
    return 0;
}
int sorted(int arr[], int n,int i)
{
        if(i==n)
            return 1;
        if(arr[i]<arr[i+1])
            i++;
        else 
            return 0;
        sorted(arr,n,i);
}