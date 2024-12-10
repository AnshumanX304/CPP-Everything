//Used same code as biparite graph (can alo be done using bfs)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

  bool dfs(vector<vector<int>>& graph,int c,int node,vector<int> &color){
      color[node]=c;
      for(auto&it:graph[node]){
          if(color[it]==-1){
              if(dfs(graph,!c,it,color)==false)return false;

          }
          else{
              if(color[it]==c){
                  return false;
              }
          }
      }
      return true;
  }


  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<vector<int>> graph(n+1);
    for(auto&it:dislikes){
      graph[it[0]].push_back(it[1]);
      graph[it[1]].push_back(it[0]);
    }

    vector<int> color(n+1,-1);
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(dfs(graph,0,i,color)==false)return false;
        }
    }
    return true;
  }
    
};

