#include<bits/stdc++.h>

using namespace std;
#define ld long double
#define ll long long 
#define lli long long int 
#define  vi vector<int>
#define vl vector<long long int>
#define pb push_back
// #define vp vector<pair<int,int>>
#define vpl vector<pair<long long int, long long int>>
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,n) for(lli i=0;i<n;i++)
int main(){   

    int n;
    cin>>n;
    vector<int> va(n);
    int num;
    cout<<"Enter the array elements ::"<<endl;
    repl(i,n)
        cin>>va[i];
    cout<<"Enter the element whose upper bound is to be found :"<<endl;
    cin>>num;
    
            
    lli low=0;
    lli high=va.size()-1;
    while(low<high){
        int mid=(low+high)/2;
        if(num>=va[mid]){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    
    if(low<va.size() && va[low]<=num)  //to check if the element pointed by low is less than or equal to the number or not
        low++;

    cout<<"Upper bound of given element is :"<<endl;
    cout<<low<<" ";

    return 0;
}