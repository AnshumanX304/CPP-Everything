#include<bits/stdc++.h>
using namespace std;

//understand this question through dp table of dp on subsequences 

//here in substrings the substring is a continuous part of a string and hence we only need to check if the 
//diagonally previous term has any value or not if it has a value then that number of terms have been same before given term 
//so work on it and add that number to given term and compare it with ans variable it it is greater than
//its current value then store it in the variable 
//return answer variable at the end 

int lcs(string &s, string &t){
    // Write your code here.
    int n=s.size();
    int m=t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int ans=INT_MIN;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
            }
            else
                dp[i][j]=0;
        }
    }
    return ans;

}
 
//-4 -4 -3
//4 4 3 0

//-4 4 -4 4 -3 0

//-18 -18 -17 
//15 13 13 12

//-18 15 -18 13 -17 13 12
