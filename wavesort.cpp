#include<iostream>
using namespace std;
void wavesort(int [],int);
void swap(int[],int,int);
int main()
{
    cout<<"Enter the size of the array ::::"<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array :::"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    wavesort(arr,n);
    cout<<"Wave sorted array is ::::"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
    return 0;
}
void wavesort(int arr[],int n)
{
    for(int i=1;i<n;i+=2)
    {
        if(arr[i]>arr[i-1])
            swap(arr,i,i-1);
        if(arr[i]>arr[i+1] && i<=n-1)
            swap(arr,i,i+1);

    }

}
void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}