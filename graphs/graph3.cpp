// this code is for 1 based indexing graph
//code for bfs traversal in a graph 

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
    cout<<endl;
    for(int i=0;i<=n;i++){
        cout<<i<<"  ";
        for(auto&it:adj[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    vector<int> bfs;
    vector<int> visited(n+1,0);
    queue<int> q;
    q.push(1);
    visited[1]=1;
    cout<<endl;
    while(!q.empty()){
        int num=q.front();
        q.pop();
        bfs.push_back(num);
        for(auto&it:adj[num]){
            if(visited[it]!=1){
                q.push(it);
                visited[it]=1;
            }
        }
    }
    for(auto&it:bfs){
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