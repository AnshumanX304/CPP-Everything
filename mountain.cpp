#include<iostream>
using namespace std;
//This program is made to find the element in the mountain array using binary search 
//Eg-:For array Arr={1,2,3,4,5,4,3,2,1},if 2 is to be found then output should be its index number i.e. 1.
int main()
{
    cout<<"Enter the size of the array :::"<<endl;
    int n1;
    cin>>n1;
    int arr[n1];
    for(int i=0;i<n1;i++)
        cin>>arr[i];
        
    cout<<"enter the element to be found :::"<<endl;
    int n;
    cin>>n;
    int beg=0;
    int last=n-1;
    int mid;
    for(int i=0;i<n;i++)
    {   mid=(beg+last)/2;
        if(arr[mid]==n)
        {       cout<<"Required output is :::"<<endl;
                cout<<arr[mid];
                cout<<mid;
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

    return 0;
}