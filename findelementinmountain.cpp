#include<iostream>
using namespace std;
void firsthalf(int arr[],int beg,int last,int n)
{
    int mid=(beg+last)/2;
    if(arr[mid]==n)
        cout<<mid;
    if(arr[mid]>n)
        last=mid;
    else    
        beg=mid;
}
int main()
{
    cout<<"Enter the size of the array :::"<<endl;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"enter the element to be found ::::"<<endl;
    int n1;
    cin>>n1;
    int beg=0;
    int last=n-1;
    int mid;
    for(int i=0;i<n;i++)
    {   mid=(beg+last)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
        {    
                break;
        }    
        if(arr[mid]>arr[mid+1])
        {       
                last=(last+beg)/2;
        }
        if(arr[mid]<arr[mid+1])
        {   
            beg=(beg+last)/2;
        }
    }
    firsthalf(arr,beg,mid,n1);
    firsthalf(arr,mid,last,n1);

    return 0;
}