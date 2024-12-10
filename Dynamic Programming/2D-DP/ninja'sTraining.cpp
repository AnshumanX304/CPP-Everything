//Problem Link-:https://www.codingninjas.com/studio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
//YT Link-: https://www.youtube.com/watch?v=AE39gJYuRog&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=8


//Recursion with memoisation approach

#include<bits/stdc++.h>
using namespace std;
int solve(int day,int idx,vector<vector<int>> &points,vector<vector<int>>&dp){

    
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=idx){
                maxi=max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[day][idx]!=-1)return dp[day][idx];
    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=idx){
            int point=points[day][i]+solve(day-1,i,points,dp);

            maxi=max(maxi,point);
        }
    }
    return dp[day][idx]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return solve(n-1,3,points,dp);
}



//Tabulation Approach

// int ninjaTraining(int n, vector<vector<int>> &points)
// {
//     vector<vector<int>> dp(n,vector<int>(4,-1));

//     dp[0][0]=max(points[0][1],points[0][2]);
//     dp[0][1]=max(points[0][2],points[0][0]);
//     dp[0][2]=max(points[0][0],points[0][1]);
//     dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));

     
//     for(int day=1;day<n;day++){
//         for(int last=0;last<4;last++){
//             int maxi=0;
//             for(int i=0;i<3;i++){
//                 if(i!=last){
//                     int point=points[day][i]+dp[day-1][i];
//                     maxi=max(maxi,point);
//                 }
                
//             }
//             dp[day][last]=maxi;
//         }
//     }
//     return dp[n-1][3];
// }

