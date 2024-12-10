#include<iostream>
using namespace std;
void countsort(int[],int);
int main()
{
    cout<<"Enter the size of the array :::"<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the array :::"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    countsort(arr,n);
    cout<<"Sorted array is :::"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
    return 0;

}
void countsort(int arr[],int n)
{
    int k=arr[0];
    for(int i=0;i<n;i++)
    {
        k=max(k,arr[i]);
    }
    int count[k+1]={0};
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    for(int i=1;i<=k;i++)
        count[i]+=count[i-1];
        
    int answer[n];
    for(int j=n-1;j>=0;j--)
    {   count[arr[j]]=count[arr[j]]-1;
        answer[count[arr[j]]]=arr[j];
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=answer[i];
    }
}