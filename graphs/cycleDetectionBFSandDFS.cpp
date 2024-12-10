//gfg link-> https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph
//yt link-> https://www.youtube.com/watch?v=BPlrALf1LDU&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=7

// Program to detect cycle in a graph using bfs and dfs


//here difference in function definition of dfs anf bfs is that we use an extra argument parent in dfs 

#include<bits/stdc++.h>
using namespace std;


//function for cycle detection using bfs
bool detectcyclebfs(int src,vector<int> visited,vector<int> adj[]){
    visited[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty()){
        int src=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto&it:adj[src]){
            if(!visited[it]){
                visited[it]=1;
                q.push({it,src});
            }
            else{
                if(it!=parent)return true;
            }
        }
    }
    return false;
}



//function for cycle detection using dfs
bool detectcycledfs(int src,int parent,vector<int> visited, vector<int> adj[]){
    visited[src]=1;
    for(auto&it:adj[src]){
        if(!visited[it]){
            if(detectcycledfs(it,src,visited,adj))return true;
        }
        else{
            if(it!=parent){
                return true;
            }
        }
    }
    return false;
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
    // for(int i=0;i<m;i++){
    //     cin>>u>>v;                           //for storing directed graph
    //     adj[u].push_back(v);
    // }
    // for(int i=0;i<=n;i++){
    //     cout<<i<<"  ";
    //     for(auto&it:adj[i]){
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int> visitedBFS(n+1,0);

    bool flag1=0;
    for(int i=1;i<=n;i++){
        if(!visitedBFS[i]){
            if(detectcyclebfs(i,visitedBFS,adj)){
                cout<<true<<endl;
                flag1=1;
                break;
            }
        }    
    }
    if(flag1==0){
        cout<<false<<endl;
    }

    vector<int> visitedDFS(n+1,0);

    bool flag2=0;
    for(int i=1;i<=n;i++){
        if(!visitedDFS[i]){
            if(detectcycledfs(i,-1,visitedDFS,adj)){
                cout<<true<<endl;
                flag2=1;
                break;
            }
        }    
    }
    if(flag2==0){
        cout<<false<<endl;
    }
    

    return 0;

}