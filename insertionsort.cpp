#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int v[n];
    cout<<"Enter the elements ::"<<endl;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<n;i++){
        int temp=v[i];
        int j=i-1;
        while(j>=0 && v[j]>temp){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=temp;
        
    }
    cout<<"Sorted array is ::"<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}