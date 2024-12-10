#include<bits/stdc++.h>
using namespace std;


//refer to the 2d dp array in the image stored in same folder


//in this we basically move diagonally i.e first from 0,0 to n-1,n-1 then from (0,1) to (n-2,n-1) and so on
//first diagonal element will have elememts 
class Solution {
public:

    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n));

        int start=-1;
        int end=-1;

        int maxlen=0;

        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap;j<n;i++,j++){
                if(gap==0){
                    dp[i][j]=1;
                }
                else if(gap==1){
                    if(s[i]==s[j]){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]==1){
                        dp[i][j]=1;
                    }
                    else{
                        dp[i][j]=0;
                    }
                }

                if(dp[i][j]==1){
                    if(gap+1>maxlen){
                        maxlen=gap+1;
                        start=i;
                        end=j;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};