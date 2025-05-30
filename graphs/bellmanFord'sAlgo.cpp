//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    
    
    //Time Complexity-> O(N*E)
    
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
       vector<int> dist(V);
       for(int i=0;i<V;i++){
           dist[i]=1e8;
       }
       dist[S]=0;
       
       for(int i=0;i<V;i++){
           for(int j=0;j<edges.size();j++){
               int parent=edges[j][0];
               int child=edges[j][1];
               int wt=edges[j][2];
               if(dist[parent]!=1e8 && dist[parent]+wt<dist[child]){
                   dist[child]=dist[parent]+wt;
               }
           }
       }
       
       //For checking negative weight cycles after V-1 edge relaxations 
       //If after V-1 iterations also we are unable to find the shortest path to any of the node then we will
       //return -1 in an array 

       
       for(int j=0;j<edges.size();j++){
            int parent=edges[j][0];
            int child=edges[j][1];
            int wt=edges[j][2];
            if(dist[parent]!=1e8 && dist[parent]+wt<dist[child]){
                return {-1};
            }
        }
       
       return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends