//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


//  Dijkastra's algo can also be implemented using queue but we use priority queue instead beacause it is
//faster and better. For deep understanding follow the youtube video link.

//Question Link-: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix
//YT Solution-: https://www.youtube.com/watch?v=V6H1qAeB-l4&t=1062s

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V);
        for(int i=0;i<V;i++){
            dist[i]=1e9;
        }
        dist[S]=0;
        pq.push({0,S});
        vector<int> visited(V,0);
        
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
           
            pq.pop();
            if(visited[node])continue;
            visited[node]=1;
            
            for(auto&it:adj[node]){
                int edgeWeight=it[1];
                int adjNode=it[0];
                if(wt+edgeWeight<dist[adjNode]){
                    dist[adjNode]=wt+edgeWeight;
                    pq.push({dist[adjNode],adjNode});
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends











// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// 1 2 3   5 6 7   9 10 11    13 14 15    17 18 19