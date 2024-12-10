#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        string temp="#";
        for(int i=0;i<s.size();i++){
            temp.push_back(s[i]);
            temp.push_back('#');
        }
        s=temp;
        int n=s.size();

        int l=0; 
        int r=0;  

        vector<int> p(n, 0); 

        int maxlen=0; 
        int maxidx=0;  

        for(int i=0;i<n;i++){  
            if(i<r) {
                p[i]=min(r-i,p[l+(r-i)]);
            }

            while(i+p[i]+1<n && i-p[i]-1>=0 && s[i+p[i]+1]==s[i-p[i]-1]){
                p[i]++;
            }
            
            if(i+p[i]>r){
                r=i+p[i];
                l=i-p[i];
            }

            if(maxlen<p[i]){
                maxlen=p[i];
                maxidx=i;
            }
        }
        
        string sol="";
        for(int i=maxidx-maxlen;i<=maxidx+maxlen;i++){
            if(s[i]!='#'){
                sol.push_back(s[i]);
            }
        }
        return sol;
    }
};