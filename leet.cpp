#include<iostream>
using namespace std;
void leet(int[],int);   //function to print only even numbers or the numbers with even digits
int main()
{
    int n;
    cout<<"Enter the size of the array :::"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements :::"<<endl;
    for(int i=0;i<n;i++)
    {
            cin>>arr[i];
    }
    cout<<"Required array elements are ::"<<endl;
    leet(arr,n);
    return 0;
}
void leet(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
            if(arr[i]%2==0)
            {
                    cout<<arr[i]<<endl;
            }
            if(arr[i]%2!=0)
            {       int temp=arr[i];
                    int k=0;
                    while(temp!=0)
                    {
                        temp=temp/10;
                        k++;
                    }
                    if(k%2==0)
                        cout<<arr[i]<<endl;
            }
    }
}