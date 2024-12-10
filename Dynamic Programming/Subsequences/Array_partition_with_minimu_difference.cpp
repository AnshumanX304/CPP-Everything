#include<bits/stdc++.h>
using namespace std;

//only questtion which needs clear understanding of dp array and how it works
//Suppose you have an (idx x sum) 2d dp array then for a cell having row number as idx1 and column number as 
//col1 will represent the answer uptil that index of the array and for given sol1 value.

//in short dp array carries most optimal solution for all possible combinations in the given question.

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	int target=0;
	for(int i=0;i<n;i++)target+=arr[i];
	

	vector<vector<bool>> dp(n,vector<bool>(target/2+1,false));
	for(int i=0;i<n;i++){
		dp[i][0]=true;
	}

	if(arr[0]<=target)
		dp[0][arr[0]]=true;

	for(int i=1;i<n;i++){
		for(int j=1;j<=target/2;j++){
			bool nottake=dp[i-1][j];
			bool take=false;
			if(arr[i]<=j)take=dp[i-1][j-arr[i]];

			dp[i][j]=take|nottake;
		}
	}
	int ans=1e9;
	for(int i=0;i<=target/2;i++){
		if(dp[n-1][i]==true){
			ans=min(ans,abs((target-i)-i));
		}
	}
	return ans;

}
