

#include<bits/stdc++.h>
using namespace std;


//DP+Memoisation approach

// int solve(int idx,int w,vector<int> &profit, vector<int> &weight,vector<vector<int>> &dp){
//     if(idx==0){
//         return (w/weight[0])*profit[0];
//     }
//     if(dp[idx][w]!=-1)return dp[idx][w];
//     int nottake=0+solve(idx-1,w,profit,weight,dp);
//     int take=INT_MIN;
//     if(w>=weight[idx]){
//         take=profit[idx]+solve(idx,w-weight[idx],profit,weight,dp);
//     }
//     return dp[idx][w]=max(take,nottake);
// }
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    // vector<vector<int>> dp(n,vector<int>(w+1,-1));
    // return solve(n-1,w,profit,weight,dp);


    //Tabulation approach

    vector<vector<int>> dp(n,vector<int>(w+1,0));
    for(int i=0;i<=w;i++){
        dp[0][i]=((int)(i/weight[0]))*profit[0];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=w;j++){
            int nottake=dp[i-1][j];
            int take=0;
            if (j >= weight[i]) {
              take = profit[i]+dp[i][j-weight[i]];
            }
            dp[i][j]=max(take,nottake);
        }
    }
    return dp[n-1][w];

}