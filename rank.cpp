#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter the row and column of the the matrix ::::::"<<endl;
    int r,c;
    cin>>r>>c;
    int arr[r][c];
    for(int i=0;i<r;i++)
    {   cout<<"Enter the elements in the "<<i+1<<"th row::::"<<endl;
        for(int j=0;j<c;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int k=0;k<r;k++)
    {
        for(int i=0;i<c;i++)
        {
            arr[k][i]=arr[k][i]/arr[k][k];
            cout<<arr[k][i];
        }
        for(int j=k+1;j<r;j++)
        {
            for(int l=0;l<c;l++)
            {
                arr[j][l]=arr[j][l]-(arr[j][k]*arr[k][l]);
            }
        }
    }
    cout<<"array is ::::"<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}