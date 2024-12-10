// Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).
// The matching should cover the entire input string (not partial).


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isstars(string &p,int pos){
        for(int i=pos;i>=0;i--){
            if(p[i]!='*')
                return false;
        }
        return true;
    }


    bool solve(string &s,string &t,int i,int j,vector<vector<int>> &dp){

        if(i<0 && j<0){
            return true;
        }

        if(i>=0 && j<0){
            return false;
        }

        if(i<0 && j>=0){
            return isstars(t,j);
        }

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==t[j] || t[j]=='?'){
            return dp[i][j]=solve(s,t,i-1,j-1,dp);    // ? or equal characters mean the same thing cause 
        }                                             // ? can be replaced with equivalent character of other string.
        else{
            if(t[j]=='*'){
                return dp[i][j]=solve(s,t,i-1,j,dp)||solve(s,t,i,j-1,dp);  // * can correspond to either free space leading to i-1 or 
            }                                                              // it can corresond to the value (like-> ab* and asdf
            else                                                           //can mean ab and asdf or ab* and asd where f is considered to be matched with one of the sequence which might replace *)
                                                                           //leading to j-1 and i remaining at the same place i.e. at * for further matching.
                return dp[i][j]=false;                                                             
            

        }
    }


    bool isMatch(string s, string p) {

        int n=s.size();
        int m=p.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        return solve(s,p,n-1,m-1,dp);

    }
};