#include<bits/stdc++.h>
using namespace std;
int solve(string &s,string &t,int i,int j,vector<vector<int>> &dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j])return dp[i][j]=1+solve(s,t,i-1,j-1,dp);
  
    return dp[i][j]=max(solve(s,t,i-1,j,dp),solve(s,t,i,j-1,dp));

}
int main(){
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // cout<<solve(s,t,n-1,m-1,dp);

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<endl;

    int i=n;
    int j=m;
    string ans;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans.push_back(s[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else
            j--;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}