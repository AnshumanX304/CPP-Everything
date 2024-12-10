#include <bits/stdc++.h> 
using namespace std;
int mod =(int)1e9+7;


//recursion + memoisation


// int solve(vector<int>&arr,vector<vector<int>> &dp,int idx,int target){
//     if(idx==0){
//         if(target==0 && arr[0]==0)
//             return 2;
//         if(target==0 || target==arr[0])
//             return 1; 
//         return 0;
//     }

//     if(dp[idx][target]!=-1)return dp[idx][target];
//     int nottake=solve(arr,dp,idx-1,target);
//     int take=0;
//     if(target>=arr[idx])take=solve(arr,dp,idx-1,target-arr[idx]);

//     return dp[idx][target]=(take+nottake)%mod;
// }

// int countPartitions(int n, int d, vector<int> &arr) {
//     // Write your code here.
//     int sum=0;
//     for(int i=0;i<n;i++){
//         sum+=arr[i];
//     }

//     if(sum-d<0) return 0;
//     if((sum-d)%2==1){
//         return 0;
//     }
//     int target=(sum-d)/2;
//     vector<vector<int>> dp(n,vector<int>(target+1,-1));
//     return solve(arr,dp,n-1,target);

// }


//Tabulation approach


int countPartitions(int n, int d, vector<int> &arr) {

    // Write your code here.
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }


    // s1, s2 be two partitions
    //s1=sum-s2
    //d=s1-s2
    //d=sum-s2-s2
    //d=sum-2s2
    //s2=(sum-d)/2


    if(sum-d<0)return 0;
    if((sum-d)%2==1){
        return 0;
    }
    
    int target=(sum-d)/2;
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    if(arr[0]==0)dp[0][0]=2;
    else dp[0][0]=1;

    if(arr[0]!=0 && arr[0]<=target)dp[0][arr[0]]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=target;j++){
            int take=dp[i-1][j];
            int nottake=0;
            if(j>=arr[i])nottake=dp[i-1][j-arr[i]];
            
            dp[i][j]=(take+nottake)%mod;
        }
    }
    return dp[n-1][target];
    
    
    
}



