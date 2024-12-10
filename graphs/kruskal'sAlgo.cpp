//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//--------------------------------------------------KRUSKAL'S ALGORITHM--------------------------------------------------------------

//1-> In kruskal's algorithm we need to first arrange the edges as per increasing order of their weights => {weight,{node1,node2}}
//2-> After that we need to iterate over those edges and see if the nodes of these edges belong to common parent or not
//3-> If they do not belong to common parent we make them belong to common parent using union operation
//     and add the weights to the ans variable 
//Once all the edges are traversed we simply return our answer

class disjointSet{
    private:
    vector<int> rank;
    vector<int> parent;
    public:
    disjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUParent(int node){
        if(parent[node]==node)return node;
        return parent[node]=findUParent(parent[node]);   //with path compression
        // return findUParent(parent[node]);    // without path compression 
    }

    void unionByRank(int node1,int node2){
        int p_node1=findUParent(node1);
        int p_node2=findUParent(node2);
        if(p_node1==p_node2)return;
        // else{
        //     parent[node1]=node2;       //these commented lines represent normal union without using rank or size but path 
        // }                               //compression is still used 
                                      
        
        if(rank[p_node1]>rank[p_node2]){
            parent[p_node2]=p_node1;

        }
        else if(rank[p_node2]>rank[p_node1]){
            parent[p_node1]=p_node2;
        }
        else{
            parent[p_node2]=p_node1;
            rank[p_node1]++;
        }
    }

};



class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto&it:adj[i]){
                int adjNode=it[0];
                int wt=it[1];
                int node=i;
                edges.push_back({wt,{node,adjNode}});
            }
        }
        
        sort(edges.begin(),edges.end());
        int dist=0;
        disjointSet ds(V);
        for(auto&it:edges){
            int wt=it.first;
            int node=it.second.first;
            int adjNode=it.second.second;
            
            if(ds.findUParent(node)!=ds.findUParent(adjNode)){
                ds.unionByRank(node,adjNode);
                dist+=wt;
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