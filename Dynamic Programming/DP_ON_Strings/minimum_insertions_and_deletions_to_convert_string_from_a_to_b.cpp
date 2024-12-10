#include<bits/stdc++.h>
using namespace std;

// IN THIS QUESTION WE WILL CALCULATE THE LCS OF BOTH STRINGS 
// NOW FOR STRING A WE NEED TO REMOVE ALL THE CHARACTERS EXCEPT THE ONE'S THAT ARE PART OF THE LCS
// AND ADD THE CHARACTERS FROM STRING B (EXCEPT THE ONE'S THAT ARE PART OF LCS)
//SO ITS JUST ADDING LENGTH OF BOTH STRINGS AND REMOVING 2 TIMES THE LENGTH OF LCS FROM IT.

//Recursion+memoisation approach

// int solve(string &s,string &t,int i,int j,vector<vector<int>> &dp){
//     if(i<0 || j<0)return 0;
//     if(dp[i][j]!=-1)return dp[i][j];
//     if(s[i]==t[j])return dp[i][j]=1+solve(s,t,i-1,j-1,dp);
//     else 
//         return dp[i][j]=max(solve(s,t,i-1,j,dp),solve(s,t,i,j-1,dp));

// }
// int canYouMake(string &s1, string &s2){
//     // Write your code here.
//     int n=s1.size();
//     int m=s2.size();
//     vector<vector<int>> dp(n,vector<int> (m,-1));
//     return n+m-2*solve(s1,s2,n-1,m-1,dp);
// }


//tabulation approach

int canYouMake(string &s, string &t){
    // Write your code here.
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return n+m-2*dp[n][m];
}