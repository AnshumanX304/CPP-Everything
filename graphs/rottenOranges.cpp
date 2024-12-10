//this is a leetcode question based on bfs 
//refer to notes for more description 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int visited[n][m];
        int cntfresh=0;
        int cnt=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                else{
                    visited[i][j]=0;
                }
                if(grid[i][j]==1)
                    cntfresh++;
            }
        }
        int tm=0;
        int irow[]={-1,0,1,0};
        int icol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            for(int i=0;i<4;i++){
                int nrow=row+irow[i];
                int ncol=col+icol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    visited[nrow][ncol]=2;
                    q.push({{nrow,ncol},t+1});
                    cnt++;
                }
            }

        }
        if(cnt!=cntfresh)
            return -1;
        
        return tm;

    }
};
// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         int visited[n][m];
//         queue<pair<pair<int,int>,int>> q;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==2){
//                     q.push({{i,j},0});
//                     visited[i][j]=2;
//                 }
//                 else{
//                      visited[i][j]=0;
//                 }
//             }
//         }
//         int tm=0;
//         int irow[]={-1,0,1,0};
//         int icol[]={0,1,0,-1};
//         while(!q.empty()){
//             int row=q.front().first.first;
//             int col=q.front().first.second;
//             int t=q.front().second;
//             q.pop();
//             tm=max(tm,t);
//             for(int i=0;i<4;i++){
//                 int nrow=row+irow[i];
//                 int ncol=col+icol[i];
//                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && grid[nrow][ncol]==1){
//                     visited[nrow][ncol]=2;
//                     q.push({{nrow,ncol},t+1});
//                 }
//             }

//         }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==1 && visited[i][j]==0){
//                     return -1;
//                 }
//             }
//         }
//         return tm;

//     }
// };