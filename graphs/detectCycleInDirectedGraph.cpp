//VideoLink=https://www.youtube.com/watch?v=9twcmtQj4DU&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=12
//GFG Solution Link=https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


//directed graph code is different from undirected one because here we do not need to keep track of the parent node 
//as we cannot traverse backwards and each node have just one parent 



// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool findpath(vector<int> adj[],vector<int>&ispath,vector<int> &isvisited,int val){
        isvisited[val]=1;
        ispath[val]=1;
        for(int i=0;i<adj[val].size();i++){
            if(!isvisited[adj[val][i]]){
                if(findpath(adj,ispath,isvisited,adj[val][i]))return true;
                
            }
            else{
                if(ispath[adj[val][i]]==1)
                return true;
            }
        }
        ispath[val]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> ispath(V,0);
        vector<int> isvisited(V,0);
        for(int i=0;i<V;i++){
            if(isvisited[i]==0){
                if(findpath(adj,ispath,isvisited,i))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends