#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> weight, vector<int> value, int idx, int maxWeight,vector<vector<int>> &dp) {
	if(idx==0){
		if(weight[0]<=maxWeight)return value[0];
		return 0;
	}

	if(dp[idx][maxWeight]!=-1)return dp[idx][maxWeight];
	int nottake=0+solve(weight,value,idx-1,maxWeight,dp);
	int take=INT_MIN;
	if(weight[idx]<=maxWeight)
		take=value[idx]+solve(weight,value,idx-1,maxWeight-weight[idx],dp);
	return dp[idx][maxWeight]=max(take,nottake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return solve(weight,value,n-1,maxWeight,dp);
}