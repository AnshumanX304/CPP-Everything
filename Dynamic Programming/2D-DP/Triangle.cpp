//In  this question we need to find the shortest path in a triangular grid having fixed starting point (0,0) but the ending point
//may differ 
//The path will end at the last row of the triangular matrix and the end may be at any column depending on the shortest path.


#include <bits/stdc++.h> 
using namespace std;
int solve(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>> &dp){
	if(i==n-1)return triangle[i][j];
	if(dp[i][j]!=-1)return dp[i][j];
	int l=triangle[i][j]+solve(i+1,j,triangle,n,dp);
	int lr=triangle[i][j]+solve(i+1,j+1,triangle,n,dp);

	return dp[i][j]=min(l,lr);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>> dp(n,vector<int> (n,-1));
	return solve(0,0,triangle,n,dp);

}