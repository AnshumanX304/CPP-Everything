//JAI SHREE RAM
#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long 
#define lli long long int 
#define vi vector<int>
#define vl vector<long long int>
#define pb push_back
#define vpi vector<pair<int,int>>
#define vpl vector<pair<long long int, long long int>>
#define rep(i,a,n) for(int i=0;i<n;i++)
#define repl(i,a,n) for(lli i=a;i<n;i++)
#define mpi map<int,int>
#define mpl map<lli,lli>
#define maxe max_element
#define mine min_element
#define pie 1.0l*acos(-1)


    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    lli test;
    cin>>test;
    while(test--){

        lli n;
        cin>>n;
        int start=1;
        int cnt=0;
        while(start<n){
            start=start*2+2;
            cnt++;
        }
        cout<<cnt+1<<endl;
        
        

    }

    
    
    return 0;
}