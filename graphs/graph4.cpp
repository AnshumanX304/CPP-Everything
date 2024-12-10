// this code is for 1 based indexing graph
//code for dfs traversal in a graph 

#include<bits/stdc++.h>
using namespace std;
void dfs(int node,vector<int>adj[],vector<int> &ls,vector<int> &visited){
    visited[node]=1;
    ls.push_back(node);
    for(int i=adj[node].size()-1;i>=0;i--){
        if(!visited[adj[node][i]])
            dfs(adj[node][i],adj,ls,visited);
    }
}
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
    cout<<endl;
    for(int i=0;i<=n;i++){
        cout<<i<<"  ";
        for(auto&it:adj[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    vector<int> visited(n+1,0);
    vector<int> ls;


    cout<<"DFS traversal of given graph is :"<<endl;
    dfs(1,adj,ls,visited);
    for(auto&it:ls){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;

}

// 5 6 

// 1 2
// 1 3
// 3 4
// 4 2
// 2 5
// 4 5