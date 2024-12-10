//WE ARE GIVEN A MIXIMUM HEAP WE NEED TO SORT THE ARRAY USING IT
#include<iostream>
using namespace std;
void heapify(int arr[],int size,int i)
{
    int left=2*i;
    int right=2*i+1;
    int pos=i;
    if(arr[pos]<arr[left] && left<=size)
    {
        pos=left;
    }
    if(arr[pos]<arr[right] && right<=size)
    {
        pos=right;
    }
    if(pos!=i)
    {
        swap(arr[pos],arr[i]);
    }
}
void heapsort(int arr[],int n)
{
    int size=n;
    while(size>1)
    {
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}
int main()
{
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--)
    {
        heapify(arr,n,i);
    }
    cout<<"printing the array now :"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    heapsort(arr,5);
    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
