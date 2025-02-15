//This is code for z algorithm 
//The main intuition is forming the z array
//z[i]=number of prefix length that matches from begining of string (i.e. s[0]) with the string starting from index i (i.e. s[i])
//we use two pointers l and r to keep track of the boundries we have seen till now
//By boundries seen we mean that the r-l+1 length substring starting from index l has matched the same 
//length from beginning of the string i.r from index 0. (s[l].....s[r])==(s[0].....s[r-l])

#include<bits/stdc++.h>
using namespace std;
int main(){
    string text="ababacbaba";
    string pattern="aba";
    
    string s = pattern + "$" + text;
    int n=s.size();
    
    vector<int> zarray(n);
    int l=0;
    int r=0;
    zarray[0]=0;  
    
    for(int i=1;i<n;i++){
        if(i>r){
            int j=0;
            int k=i;

            while(k<n && s[j]==s[k]){
                j++;
                k++;
            }
            zarray[i]=j;
            l=i;
            r=k-1;  
        }
        else{
            if(i+zarray[i-l]>r){
                l=i;
                r++;  
                while(r<n && s[r-l]==s[r]){
                    r++;
                }
                zarray[i]=r-l;
                r--;
            }
            else{
                zarray[i]=zarray[i-l];
            }
        }
    }
    
    cout << "Pattern found at positions: ";
    for(int i=pattern.length()+1; i<n; i++){
        if(zarray[i]==pattern.length()){
            cout << (i-pattern.length()-1) << " ";
        }
    }
    cout << endl;
    
    return 0;
}