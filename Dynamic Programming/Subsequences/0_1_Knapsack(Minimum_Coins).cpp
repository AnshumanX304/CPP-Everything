#include <bits/stdc++.h> 
using namespace std;


int solve(vector<int> &num,int target,int idx,vector<vector<int>> &dp){
    if(idx==0){
        if(target%num[0]==0)return target/num[0];
        return 1e9;
    }
    if(dp[idx][target]!=-1)return dp[idx][target];      //do all stuffs
    int nottake=0+solve(num,target,idx-1,dp);
    int take=INT_MAX;
    if(target>=num[idx]){
        take=1+solve(num,target-num[idx],idx,dp);
    }


    return dp[idx][target]=min(take,nottake);       //take minimum of all steps
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,-1));
    int ans=solve(num,x,n-1,dp);
    
    if(ans>=1e9)return -1;
    return ans;

}