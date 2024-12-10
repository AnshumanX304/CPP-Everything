#include<bits/stdc++.h>
using namespace std;

class TreeAncestor {
public:
    vector<vector<int>> dp;
    TreeAncestor(int n, vector<int>& parent) {
        int rows=ceil(log2(n))+1;
        dp.resize(rows,vector<int>(n));
        for(int i=0;i<parent.size();i++){
            dp[0][i]=parent[i];
        }

        for(int i=1;i<rows;i++){
            for(int j=0;j<n;j++){
                if(dp[i-1][j]==-1){
                    dp[i][j]=-1;
                }
                else{
                    dp[i][j]=dp[i-1][dp[i-1][j]];
                }
                
            }
        }

    }
    
    int getKthAncestor(int node, int k) {
        vector<int> curr;
        int pos=0;
        while(k){
            if(k&1){
                curr.push_back(pos);

            }
            k=k>>1;
            pos++;

        }
        int ans=node;
        for(int i=0;i<curr.size();i++){
            if(ans==-1)break;
            ans=dp[curr[i]][ans];

        }
        return ans;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */