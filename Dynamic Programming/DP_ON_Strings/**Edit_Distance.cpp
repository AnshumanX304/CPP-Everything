// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character


//Recursion + memoisation approach

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int solve(string &s,string &t,int i,int j,vector<vector<int>> &dp){

        //if either of the string gets exhausted then its just like 
        //converting the string left to another one either by deleting 
        //or adding the exact number of letter from the remaining string
        //hence the index+1 of the remaining string is returned.

        if(i<0)return j+1;

        if(j<0)return i+1;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==t[j])return dp[i][j]=solve(s,t,i-1,j-1,dp); //if character matched then simply move 
                                                             //both pointers to next index

        return dp[i][j]=1+min(solve(s,t,i-1,j-1,dp),min(solve(s,t,i,j-1,dp),solve(s,t,i-1,j,dp)));
                                                            //If pointers not matched then find the
                                                            //minimum of all the possible conditions i.e.
                                                            //insertion (where one index of the answer string is moved)
                                                            //deletion (where one index of the string we are working on is moved)
                                                            //replace (where index of both index is moved, similar to when the string 
                                                            //characters are matched)
                                                            
    }
    int minDistance(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(s,t,n-1,m-1,dp);
    }
};



//Tabulation approach 


// #include <bits/stdc++.h>
// using namespace std;

// // Function to calculate the edit distance between two strings
// int editDistance(string& S1, string& S2) {
//     int n = S1.size();
//     int m = S2.size();

//     // Create a DP table to store edit distances
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//     // Initialize the first row and column
//     for (int i = 0; i <= n; i++) {
//         dp[i][0] = i;
//     }
//     for (int j = 0; j <= m; j++) {
//         dp[0][j] = j;
//     }

//     // Fill in the DP table
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             if (S1[i - 1] == S2[j - 1]) {
//                 // If the characters match, no additional cost
//                 dp[i][j] = dp[i - 1][j - 1];
//             } else {
//                 // Minimum of three choices:
//                 // 1. Replace the character at S1[i-1] with S2[j-1]
//                 // 2. Delete the character at S1[i-1]
//                 // 3. Insert the character at S2[j-1] into S1
//                 dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
//             }
//         }
//     }

//     // The value at dp[n][m] contains the edit distance
//     return dp[n][m];
// }

// int main() {
//     string s1 = "horse";
//     string s2 = "ros";

//     // Call the editDistance function and print the result
//     cout << "The minimum number of operations required is: " << editDistance(s1, s2);
//     return 0;
// }
