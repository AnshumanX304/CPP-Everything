//YT Link->https://www.youtube.com/watch?v=QGfn7JeXK54&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=14
//CodeStudio Link->https://www.codingninjas.com/studio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1


#include <bits/stdc++.h> 
using namespace std;
int solve(int i,int j1,int j2,vector<vector<int>> &grid,int n,int c,vector<vector<vector<int>>> &dp){
    
    if(j1<0 || j2<0 || j1>=c || j2>=c)return -1e8;

    if(i==n-1){
        if(j1==j2)return grid[i][j1];
        else return grid[i][j1]+grid[i][j2];
    }
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];

    int maxi=INT_MIN;

    
    for(int k=-1;k<=1;k++){
        for(int j=-1;j<=1;j++){
            int val=0;
            if(j1==j2)val=grid[i][j1];
            else val=grid[i][j1]+grid[i][j2];
            maxi=max(maxi,val+solve(i+1,j1+k,j2+j,grid,n,c,dp));
        }
    }
    return dp[i][j1][j2]=maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return solve(0,0,c-1,grid,r,c,dp);
}