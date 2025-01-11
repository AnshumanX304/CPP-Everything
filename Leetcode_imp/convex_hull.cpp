//Question Link-: https://leetcode.com/problems/erect-the-fence/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isconvex(vector<pair<int,int>> upper,vector<int> curr){
        int n=upper.size();

        pair<int,int> p1=upper[n-1];
        pair<int,int> p2=upper[n-2];
        pair<int,int> p3={curr[0],curr[1]};

        int m2=(p3.second-p2.second)*(p2.first-p1.first);
        int m1=(p2.second-p1.second)*(p3.first-p2.first);

        return m2>m1;
    }


    bool isconcave(vector<pair<int,int>> upper,vector<int> curr){
        int n=upper.size();

        pair<int,int> p1={upper[n-1].first,upper[n-1].second};
        pair<int,int> p2={upper[n-2].first,upper[n-2].second};
        pair<int,int> p3={curr[0],curr[1]};

        int m2=(p3.second-p2.second)*(p2.first-p1.first);
        int m1=(p2.second-p1.second)*(p3.first-p2.first);

        return m2<m1;
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        sort(trees.begin(),trees.end());

        vector<pair<int,int>> lower;
        vector<pair<int,int>> upper;

        for(int i=0;i<trees.size();i++){
            while(upper.size()>=2 && isconvex(upper,trees[i])){
                upper.pop_back();
            }
            upper.push_back({trees[i][0],trees[i][1]});
        }
        for(int i=0;i<trees.size();i++){
            while(lower.size()>=2 && isconcave(lower,trees[i])){
                lower.pop_back();
            }
            lower.push_back({trees[i][0],trees[i][1]});
        }

        set<pair<int,int>> se;
        for(auto&it:upper)se.insert(it);
        for(auto&it:lower)se.insert(it);

        vector<vector<int>> ans;
        for(auto&it:se){
            ans.push_back({it.first,it.second});
        }
        return ans;
        
    }
};