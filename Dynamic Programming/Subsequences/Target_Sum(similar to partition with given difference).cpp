#include<bits/stdc++.h>
using namespace std;
int mod =(int)1e9+7;
class Solution {
public:
    int solve(vector<int>&arr,vector<vector<int>> &dp,int idx,int target){
        if(idx==0){
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target==arr[0])
                return 1; 
            return 0;
        }

        if(dp[idx][target]!=-1)return dp[idx][target];
        int nottake=solve(arr,dp,idx-1,target);
        int take=0;
        if(target>=arr[idx])take=solve(arr,dp,idx-1,target-arr[idx]);

        return dp[idx][target]=(take+nottake)%mod;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        
        if(sum-target<0)return 0;
        if((sum-target)%2==1){
            return 0;
        }
        int finaltarget=(sum-target)/2;

        vector<vector<int>> dp(n,vector<int>(finaltarget+1,-1));
        return solve(nums,dp,n-1,finaltarget);
    }
};