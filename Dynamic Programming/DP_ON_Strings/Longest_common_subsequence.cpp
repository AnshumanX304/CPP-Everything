#include<bits/stdc++.h>
using namespace std;

//Recursion + memoisation


// int solve(string &s, string &t,int i,int j,vector<vector<int>> &dp){
// 	if(i<0 || j<0)return 0;
// 	if(dp[i][j]!=-1)return dp[i][j];
// 	if(s[i]==t[j])
// 		return 1+solve(s,t,i-1,j-1,dp);

// 	return dp[i][j]=max(solve(s,t,i-1,j,dp),solve(s,t,i,j-1,dp));
// }
// int lcs(string s, string t)
// {
// 	//Write your code here
// 	int n=s.size();
// 	int m=t.size();
// 	vector<vector<int>> dp(n,vector<int>(m,-1));
// 	return solve(s,t,n-1,m-1,dp);
// }


//tabulation approach

int lcs(string s, string t)
{
	//Write your code here
	int n=s.size();
	int m=t.size();
	vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1])dp[i][j]=1+dp[i-1][j-1];
			else
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[n][m];
	
}