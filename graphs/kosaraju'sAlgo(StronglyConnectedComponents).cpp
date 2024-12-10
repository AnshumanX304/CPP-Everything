//Here in kosaraju's algo

//1. Traverse the graph using initial node and while backtracking store the value of those nodes in stack
//2. Reverse the graph and store it in new adjacency list
//3. Traverse the graph by dfs again using elements in stack until stack becomes empty and count the number of times the 
//dfs was called. 
//4. The count will give the number of strongly connected components.





//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(vector<vector<int>> &adj,vector<int> &visited,stack<int>&st,int node){
	    visited[node]=1;
	    for(auto&it:adj[node]){
	        if(!visited[it])
	            dfs(adj,visited,st,it);
	    }
	    st.push(node);
	}
	
	void dfs2(vector<vector<int>> &adjT,vector<int> &visited,int node){
	    visited[node]=1;
	    for(auto&it:adjT[node]){
	        if(!visited[it])
	            dfs2(adjT,visited,it);
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int> visited(V,0);
        stack<int> st;


        for(int i=0;i<V;i++){     //STEP 1-> Normal dfs to store the values in stack in reverse order of dfs traversal
            if(!visited[i]){
                dfs(adj,visited,st,i);
            }
        }
        

        vector<vector<int>> adjT(V);  //STEP2-> Reverse the graph and store in new adjacency list
        for(int i=0;i<V;i++){
            visited[i]=0;
            for(auto&it:adj[i]){
                adjT[it].push_back(i);
            }
        }


        int scc=0;
        while(!st.empty()){         //STEP3-> Empty the stack and do dfs call for the elements popped out of it 
            int node=st.top();      // which are  unvisited
            st.pop();
            if(!visited[node]){
                scc++;
                dfs2(adjT,visited,node);
            }
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends