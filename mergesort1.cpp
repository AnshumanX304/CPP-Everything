#include<iostream>
using namespace std;
void mergesort(int arr[],int,int);
void merge(int arr[],int,int,int);
int main()
{
    cout<<"Enter the size of the array ::::"<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the values ::::"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergesort(arr,0,n);
    for(int j=0;j<n;j++)
        cout<<arr[j]<<" ";
    return 0;
}
void mergesort(int arr[],int l,int r)
{   
    if(l<r)
    {   
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
void merge(int arr[],int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++)
    {   
        a[i]=arr[i+l];
    }
    for(int j=0;j<n2;j++)
    {
        b[j]=arr[mid+j+1];
    }
    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2)
    {   
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            k++;
            i++;
        }
        else
        {
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        arr[k]=a[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=b[j];
        k++;
        j++;
    }
}