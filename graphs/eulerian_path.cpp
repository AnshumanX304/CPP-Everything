#include<bits/stdc++.h>
using namespace std;
class Solution {
public:


    void eulerianpath_dfs(int node,map<int,set<int>> &adj,vector<int> &eulerpath){
        while(!adj[node].empty()) {
            int next = *adj[node].begin();
            adj[node].erase(next);
            eulerianpath_dfs(next, adj, eulerpath);
        }
        eulerpath.push_back(node);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        map<int,int> indegree;
        map<int,int> outdegree;

        map<int,set<int>> adj;
        for(auto&it:pairs){
            indegree[it[1]]++;
            outdegree[it[0]]++;
            adj[it[0]].insert(it[1]);
        }

        int start=pairs[0][0];
        for(auto& pair:pairs){
            int u=pair[0];
            if(outdegree[u]-indegree[u]==1) {
                start=u;
                break;
            }
        }
        
        vector<int> eulerpath;

        eulerianpath_dfs(start,adj,eulerpath);
        reverse(eulerpath.begin(),eulerpath.end());

        vector<vector<int>> ans;
        for(int i=1;i<eulerpath.size();i++){
            ans.push_back({eulerpath[i-1],eulerpath[i]});
        }
        return ans;
    }
};


//Condition for existance of eulerian path-: 
//1- Odd degree nodes must be either 0 or 2 (decide as per directed or undirected graph)
//2- Graph must be connected.

//ALGORITHM:
//1> Take starting node as the node with outdegree-indegree == 1 (for directed graph) 
//   or anynode with degree odd (for undirected graph)
//2> Iterate to its adjacent node and delete the node simultaneously (check for directed and undirected accordingly)
//3>  After all the nodes have been traversed push that node in a vector
//4> After all the nodes are done reverse the vector and it has your eulerian path ready.




