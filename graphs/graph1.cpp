//  Program to represent graph in a adjacency matrix by taking no of nodes(n) and number of edges as input(m)
//space complexity is n^2 which is very high so we use adjacency list to overcome this 

#include<bits/stdc++.h>
using namespace std;
int main(){
    
    int n,m;
    cin>>n>>m;
    int adj[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            adj[i][j]=0;
        }
    }
    int u,v;
    cout<<endl;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}