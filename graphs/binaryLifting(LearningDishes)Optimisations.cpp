//JAI SHREE RAM 
#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define lli long long 
#define ll long long int 
#define vi vector<int>
#define vl vector<long long int>
#define pb push_back
#define vpi vector<pair<int,int>>
#define vpl vector<pair<long long int, long long int>>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repl(i,a,n) for(lli i=a;i<n;i++)
#define mpi map<int,int>
#define mpl map<lli,lli>
#define maxe max_element
#define mine min_element
#define pie 1.0l*acos(-1)

// Kept unchanged as it might be used elsewhere
string getBinary(int n) {
    bitset<64> b(n);
    return b.to_string();
}

vector<pair<int,int>> config;
const int MAXBIT=22;
const int MAXLEN=1e6+2;
vl parent;
vl taste;
lli dp[MAXBIT][MAXLEN];

void precalc(lli n){
    for(lli i=1;i<=n;i++){
        dp[0][i]=parent[i];
    }
    
    for(lli i=1;i<MAXBIT;i++){
        for(lli j=1;j<=n;j++){
            lli par=dp[i-1][j];
            dp[i][j]=dp[i-1][par];
        }
    }
}

// Changed: Passed adj by const reference to avoid copying
void dfs(lli currnode, lli parent, lli maxtillnow, lli currcnt, const vector<vector<lli>> &adj){
    
    if(taste[currnode]>maxtillnow){
        maxtillnow=taste[currnode];
        currcnt+=1;
    }
    
    config[currnode]={maxtillnow,currcnt};
    
    // Changed: Used range-based for loop
    for(const auto &it : adj[currnode]){
        if(it!=parent){
            dfs(it,currnode,maxtillnow,currcnt,adj);
        }
    }
}

lli solve(lli w,lli v){
    // Added: Early exit condition to avoid unnecessary computation
    if (w >= config[v].first) return 0;
    lli currcnt=config[v].second;
    
    for(int i=MAXBIT-1;i>=0;i--){
        if(config[dp[i][v]].first>w){
            v=dp[i][v];
        }
    }
    lli nextcnt=config[parent[v]].second;
    return currcnt-nextcnt;
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    lli test;
    cin>>test;
    while(test--){
        lli n;
        cin>>n;
        
        // Changed: Cleared vectors instead of recreating them
        parent.clear();
        taste.clear();
        vector<vector<lli>> adj(n+1);
        config.clear();
        
        parent.resize(n+1);
        taste.resize(n+1);
        config.resize(n+1);
        
        for(int i=1;i<=n;i++){
            cin>>taste[i];
        }
        for(int i=2;i<=n;i++){
            cin>>parent[i];
            adj[parent[i]].push_back(i);
        }
        
        precalc(n);
        
        dfs(1,-1,0,0,adj);
        
        lli curr=0;
        
        lli q;
        cin>>q;
        lli w,v;
        // Changed: Used while loop instead of for loop
        while(q--){
            cin>>v>>w;
            w^=curr;
            v^=curr;
            curr=solve(w,v);
            // Changed: Used '\n' instead of endl
            cout << curr << '\n';
        }
    }
    
    return 0;
}




