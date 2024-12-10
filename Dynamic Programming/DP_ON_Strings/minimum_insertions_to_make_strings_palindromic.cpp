#include<bits/stdc++.h>
using namespace std;


// Find the length of longest palindromic subsequence and subtract the length of the entire array from it to find insertions you need 
// to make in order to make string palindrome

//  aasdaaf ->faasdsaaf        
//  minimum insertions = total string length - length of longest palindromic subsequence (aaaa in this case)
//  minimum insertions = 7-4 = 3


int minInsertions(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];   
                }
                else 
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                
            }
        }
        return s.size()-dp[n][n];
}

