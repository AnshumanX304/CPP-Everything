#include<iostream>
using namespace std;
int main()
{
        cout<<"Enter the size of a :::"<<endl;
        int n;
        cin>>n;
        int *a[n];
        for(int i=0;i<n;i++)
        {   
            cout<<"Enter the size of array p "<<i<<" ::"<<endl;
            int n;
            cin>>n;
            int *p=new int[n];
            cout<<"Enter the elements ::::"<<endl;
            for(int j=0;j<n;j++)
            {
                cin>>p[j];
            }
            a[i]=p;


        }
        cout<<"enter the index number to be found :::"<<endl;
        int g;
        cin>>g;
        cout<<*(a[0]+g)<<" "<<*(a[0]+g)<<endl;
        
        return 0;
}