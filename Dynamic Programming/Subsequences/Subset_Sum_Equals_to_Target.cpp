#include <bits/stdc++.h> 
using namespace std;
// bool solve(int idx,int target,vector<int> &arr,vector<vector<int>> &dp){
//     if(target==0)return true;
//     if(idx==0)return (target==arr[0]);
//     if(dp[idx][target]!=-1)return dp[idx][target];
//     bool nottake=solve(idx-1,target,arr,dp);
//     bool take=false;
//     if(arr[idx]<=target)
//         take=solve(idx-1,target-arr[idx],arr,dp);
//     return dp[idx][target]=take | nottake;
    
// }
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     // Write your code here.
//     vector<vector<int>> dp(n,vector<int>(k+1,-1));
//     return solve(n-1,k,arr,dp);

// }

//tabulation approach

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool nottake=dp[i-1][j];
            bool take=false;
            if(arr[i]<=j)
                take=dp[i-1][j-arr[i]];
            
            dp[i][j]=take|nottake;
        }
    }
    return dp[n-1][k];

}
