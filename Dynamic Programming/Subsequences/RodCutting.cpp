#include<bits/stdc++.h>
using namespace std;

//Using dp on rod length

// int solve(int n,vector<int> &price,vector<int> &dp){
	
// 	if(n==0){
// 		return 0;
// 	}
// 	if(dp[n]!=-1)return dp[n];
// 	int ans=0;
// 	for(int i=0;i<n;i++){
// 		int cut=i+1;
// 		int take=price[i]+solve(n-cut,price,dp);
// 		ans=max(take,ans);
// 	}
// 	return dp[n]=ans;

// }

// int cutRod(vector<int> &price, int n)
// {
// 	// Write your code here.
// 	vector<int> dp(n+1,-1);
// 	return solve(n,price,dp);
// }

//using dp on price array


//Recursion + memoisation approach

int solve(int n,vector<int> &price,int idx,vector<vector<int>> &dp){
	if(idx==0){
		return price[0]*n;
	}
	if(dp[idx][n]!=-1)return dp[idx][n];
	int nottake=solve(n,price,idx-1,dp);
	int take=INT_MIN;
	if(n>=idx+1){
		take=price[idx]+solve(n-idx-1,price,idx,dp);
	}
	return dp[idx][n]=max(take,nottake);
}



//tabulation approach

int cutRod(vector<int> &price, int n)
{
	// Write your code here.

	// vector<vector<int>> dp(n,vector<int>(n+1,-1));
	// return solve(n,price,n-1,dp);

	vector<vector<int>> dp(n,vector<int>(n+1,0));
	for(int i=0;i<=n;i++){
		dp[0][i]=price[0]*i;
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<=n;j++){
			int nottake=dp[i-1][j];
			int take=INT_MIN;
			if(j>=i+1){
				take=price[i]+dp[i][j-i-1];
			}

			dp[i][j]=max(take,nottake);
		}
	}
	return dp[n-1][n];



}



