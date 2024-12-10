#include<bits/stdc++.h>
using namespace std;

int mod = (int)(1e9+7);


//This will work only for all positive numbers (0 should not be there)


// int solve(vector<int> &arr,int idx,int sum,vector<vector<int>> &dp){
// 	if(sum==0)return 1;
// 	if(idx==0){
// 		return arr[0]==sum;
// 	}
// 	if(dp[idx][sum]!=-1)return dp[idx][sum];
// 	int notpick=solve(arr,idx-1,sum,dp);
// 	int pick=0;
// 	if(sum>=arr[idx])pick=solve(arr,idx-1,sum-arr[idx],dp);

// 	return dp[idx][sum]=(pick + notpick)%mod;
// }
// int findWays(vector<int>& arr, int k)
// {
// 	// Write your code here.
// 	int n=arr.size();

// 	vector<vector<int>> dp(n,vector<int>(k+1,-1));
// 	// sort(arr.begin(),arr.end());
// 	// reverse(arr.begin(),arr.end());
// 	return solve(arr,n-1,k,dp);
// }


//This will work only for 0 as well

// int solve(vector<int> &arr,int idx,int sum,vector<vector<int>> &dp){
// 	if(idx==0){
//      if(sum==0 && arr[0]==0)return 2;                                    //only base case is changed and 0 is considered
//      if(sum==0 || sum==arr[0])return 1;
//      return 0;
// 	}
// 	if(dp[idx][sum]!=-1)return dp[idx][sum];
// 	int notpick=solve(arr,idx-1,sum,dp);
// 	int pick=0;
// 	if(sum>=arr[idx])pick=solve(arr,idx-1,sum-arr[idx],dp);

// 	return dp[idx][sum]=(pick + notpick)%mod;
// }
// int findWays(vector<int>& arr, int k)
// {
// 	// Write your code here.
// 	int n=arr.size();

// 	vector<vector<int>> dp(n,vector<int>(k+1,-1));
// 	// sort(arr.begin(),arr.end());
// 	// reverse(arr.begin(),arr.end());
// 	return solve(arr,n-1,k,dp);
// }


int findWays(vector<int>& arr, int k){

	int n=arr.size();
	vector<vector<int>> dp(n,vector<int>(k+1,0));
	for(int i=0;i<n;i++){
		dp[i][0]=1;
	}
	if(arr[0]<=k)dp[0][arr[0]]=1;
	for(int i=1;i<n;i++){
		for(int j=1;j<=k;j++){
			int nottake=dp[i-1][j];
			int take=0;
			if(arr[i]<=j)take=dp[i-1][j-arr[i]];
			dp[i][j]=(take+nottake)%mod;
		}
	}
	return dp[n-1][k];

}



