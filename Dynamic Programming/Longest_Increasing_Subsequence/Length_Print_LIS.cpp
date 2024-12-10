#include<bits/stdc++.h>
using namespace std;
class Solution {
public:


//Recursion + Memoisation approach


    int solve(int cur,int prev,vector<int>& nums,vector<vector<int>> &dp){


        if(cur>=nums.size())
            return 0;

        if(dp[cur][prev+1]!=-1)return dp[cur][prev+1];

        int len1=solve(cur+1,prev,nums,dp);
        int len2=INT_MIN;
        if(prev==-1 || nums[prev]<nums[cur]){
            len2=1+solve(cur+1,cur,nums,dp);
        }


        return dp[cur][prev+1]=max(len1,len2);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>> dp(n,vector<int>(n+1,-1));      //takes lot of space so a more optimised solution is required
        return solve(0,-1,nums,dp);
    }

//Tabulation Approach

    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>> dp(n+1,vector<int>(n+1,0));    //takes lot of space so a more optimised solution is required
    //     for(int cur=n-1;cur>=0;cur--){
    //         for(int prev=cur-1;prev>=-1;prev--){
    //             int len1=dp[cur+1][prev+1];
    //             int len2=INT_MIN;
    //             if(prev==-1 || nums[prev]<nums[cur]){
    //                 len2=1+dp[cur+1][cur+1];
    //             }


    //             dp[cur][prev+1]=max(len1,len2);
    //         }
    //     }
    //     return dp[0][-1+1];
    // }
};


//The above approaches had time complexity of O(n^2) and space complexity of O(n^2) as well.



//Space Optimised Approach

//With this new approach we can boil down the space complexity to O(n)
//It uses 1d dp array 
//But it still has time complexity of O(n^2) which we will optimise further but for now let's have a look at 
//better space optimised approach.


// int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n,1);
//         int maxi=INT_MIN;
//         for(int i=0;i<n;i++){
//             for(int prev=0;prev<i;prev++){
//                 if(nums[prev]<nums[i]){
//                     dp[i]=max(dp[i],1+dp[prev]);
//                 }
//             }
//             maxi=max(maxi,dp[i]);
//         }
//         return maxi;
// }


//Printing LIS using hash table method and space optimised tabulation


// int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n,1);
//         vector<int> hash(n,1);
//         int maxi=INT_MIN;
//         for(int i=0;i<n;i++){
//             for(int prev=0;prev<i;prev++){
//                 if(nums[prev]<nums[i] && 1+dp[prev]>dp[i]){
//                     dp[i]=1+dp[prev];
//                     hash[i]=prev;
//                 }
//             }
//             maxi=max(maxi,dp[i]);
//         }

//         int ans = -1;
//         int lastIndex =-1;
        
//         for(int i=0; i<=n-1; i++){
//             if(dp[i]> ans){
//                 ans = dp[i];
//                 lastIndex = i;
//             }
//         }
        
//         vector<int> temp;
//         temp.push_back(nums[lastIndex]);
        
//         while(hash[lastIndex] != lastIndex){ // till not reach the initialization value
//             lastIndex = hash[lastIndex];
//             temp.push_back(nums[lastIndex]);    
//         }
        
//         // reverse the array 
//         reverse(temp.begin(),temp.end());
// }




