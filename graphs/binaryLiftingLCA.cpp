#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> freq;
    vector<int> parent;
    vector<int> level;
    void precalc(int rows){
        int n = parent.size();
        for(int i = 0; i < n; i++){
            dp[0][i] = parent[i];
        }

        for(int i = 1; i < rows; i++){
            for(int j = 0; j < n; j++){
                if(dp[i-1][j] == -1){
                    dp[i][j] = -1;
                }
                else{
                    dp[i][j] = dp[i-1][dp[i-1][j]];
                }   
            }
        }
    }

    void prefreq(int node, int par, vector<vector<pair<int,int>>>& adj, int lev){
        parent[node] = par;
        level[node] = lev;

        for(auto& it : adj[node]){
            if(it.first != par){
                freq[it.first][it.second]++;
                for(int i=1;i<27;i++){
                    freq[it.first][i]+=freq[node][i];
                }
                
                prefreq(it.first, node, adj, lev + 1);
            }
        }
    }

    int findlca(int u, int v){
        if(level[u] > level[v]){
            swap(u, v);
        }

        int diff = level[v] - level[u];
        for(int i = 31; i >= 0; i--){
            if(diff & (1 << i)){
                v = dp[i][v];
            }
        }
        if(u == v) return u;

        for(int i = 31; i >= 0; i--){
            if(dp[i][u] != dp[i][v]){
                u = dp[i][u];
                v = dp[i][v];
            }
        }

        return parent[u];
    }

    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto& it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        int rows = 31;
        dp.resize(rows + 1, vector<int>(n));
        freq.resize(n, vector<int>(27));
        parent.resize(n);
        level.resize(n);  
        prefreq(0, 0, adj, 0);
    
        precalc(rows);
        vector<int> ans;
        for(auto& it : queries){
            int u = it[0];
            int v = it[1];
            int lca = findlca(u, v);

            vector<int> sol(27);
            int total = 0;
            int maxi = 0;
            for(int i = 1; i <= 26; i++){
                sol[i] = (freq[u][i]-freq[lca][i]) + (freq[v][i]-freq[lca][i]);

                total += sol[i];
                maxi = max(maxi, sol[i]);
            }
            ans.push_back(total - maxi);
        }
        return ans;
    }
};