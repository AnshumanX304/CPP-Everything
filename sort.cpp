#include<iostream>
using namespace std;
void mergesort(int[],int,int);
void merge(int[],int,int,int);
void countsort(int[],int);
int partition(int[],int,int);
void wavesort(int[],int);
void quicksort(int[],int,int);

int main()
{
    cout<<"Enter the size of the array :::"<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array :::"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int arr1[n];
    int arr2[n];
    int arr3[n];
    for(int i=0;i<n;i++)
    {
        arr1[i]=arr[i];
        arr2[i]=arr[i];
        arr3[i]=arr[i];
    }


    cout<<"Sorted array is :::"<<endl;
    mergesort(arr,0,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quicksort(arr1,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    countsort(arr2,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    wavesort(arr3,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr3[i]<<" ";
    }
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
    for(int i=0;i<n2;i++)
    {
        b[i]=arr[mid+i+1];
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
void quicksort(int arr[],int l,int r)
{
    if(l<r)
    {
        int pi=partition(arr,l,r);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);
    }
}
int partition(int arr[],int l,int r)
{
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++)
    {
        if(arr[j]<pivot)
        {   i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
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
        count[arr[i]]++;
    for(int i=1;i<=k;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    int answer[n];
    for(int i=0;i<n;i++)
    {
        --count[arr[i]];
        answer[count[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=answer[i];
    }
}
void wavesort(int arr[], int n)
{
    for(int i=1;i<n;i=i+2)
    {
        if(arr[i]>arr[i-1])
            swap(arr[i],arr[i-1]);
        if(arr[i]>arr[i+1] && i<=n-1)
            swap(arr[i],arr[i+1]);
    }
}