// Program to represent graph in a adjacency matrix by taking no of nodes(n) and number of edges as input(m)
//space complexity is n^2 which is very high so we use adjacency list to overcome this 

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    int u,v;
    cout<<endl;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for(int i=0;i<m;i++){
    //     cin>>u>>v;                           //for storing directed graph
    //     adj[u].push_back(v);
    // }
    for(int i=0;i<=n;i++){
        cout<<i<<"  ";
        for(auto&it:adj[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;

}