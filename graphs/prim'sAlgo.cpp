//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        
        pq.push({0,0});     //Always remember to put edge weight first and then node value
                            //because prim's algo strictly uses priority by edge weight
                            
                            
        vector<int> visited(V,0);
        int dist=0;
        
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int weight=it.first;
            pq.pop();
            
            if(visited[node]==1)continue;
            visited[node]=1;
            dist+=weight;
            for(auto&it:adj[node]){
                int adjNode=it[0];    //gfg sucks at giving input and its explanation !!
                int adjWeight=it[1];
                if(!visited[adjNode]){
                    pq.push({adjWeight,adjNode});    //edge weight should be inserted before
                                                    //node value
                }
            }
        }
        return dist;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends