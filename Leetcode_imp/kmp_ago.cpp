//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        void solve(vector<int> &lps,string &pat){
            
            
            lps[0]=0;
            int i=1;
            int m=pat.size();
            int length=0;
            while(i<m){
                if(pat[i]==pat[length]){
                    length++;
                    lps[i]=length;
                    i++;
                }
                else{
                    if(length!=0){
                        length=lps[length-1];
                    }
                    else{
                        lps[i]=0;
                        i++;
                    }
                }
            }
        }
        vector <int> search(string pat, string txt)
        {
           int n=txt.size();
           int m=pat.size();
           vector<int> lps(m);
           solve(lps,pat);
           
           
           int i=0;
           int j=0;
           
           vector<int> ans;
           
           while(i<n){
               if(pat[j]==txt[i]){
                   i++;
                   j++;
               }
               
               if(j==m){
                   ans.push_back(i-j+1);
                   
                   j=lps[j-1];
               }
               else{
                   if(i<n && pat[j]!=txt[i]){
                       if(j!=0){
                           j=lps[j-1];
                           
                       }
                       else{
                           i++;
                       }
                   }
               }
               
               
               
           }
           return ans;
           
           
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends