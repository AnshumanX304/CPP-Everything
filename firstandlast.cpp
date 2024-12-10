#include<iostream>
using namespace std;
int *firstandlast(int[],int,int,int,int[],int);
int main()
{   
    cout<<"Enter the size of the array ::::"<<endl;
    int n;
    cin>>n;
    int x[n];
    cout<<"Enter the elements in the array :::"<<endl;
    for(int i=0;i<n;i++)
    {   
        cin>>x[i];
    }
    cout<<"Enter the number whose first and last appearence is to be found :::"<<endl;
    int j;
    cin>>j;
    int *y=firstandlast(x,0,j,n,0,0);
    for(int i=0;i<3;i++)
        cout<<y[i];
}
int *firstandlast(int x[],int i,int j,int n,int y[],int a)
{
        if(i==n)
            return y;
        if(x[i]==j)
        {
                y[a]=i;
                a++;
        }
        firstandlast(x,i+1,j,n,y,a);

}
