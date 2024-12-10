
//ROBIN KARP WITH DOUBLE HASHING BOILS DOWN THE WORST CASE COMPLEXITY OF THE ALGORITHM FROM O(N*M) TO ALMOST O(N+M)


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    #define lli long long int
    lli coef1=26;
    lli coef2=27;
    
    lli prime1=1e9+7;
    lli prime2=1e9+33;
    
    pair<lli,lli> calchash(string &str,lli m){
        lli factor1=1;
        lli factor2=1;
        lli hash1=0;
        lli hash2=0;
        for(lli i=m-1;i>=0;i--){
            hash1+=((str[i]-'a')*factor1)%prime1;
            hash1%=prime1;
            factor1=(factor1*coef1)%prime1;  

            hash2+=((str[i]-'a')*factor2)%prime2;
            hash2%=prime2;
            factor2=(factor2*coef2)%prime2;
        }
        
        return {hash1%prime1,hash2%prime2};
    }
    
    lli strStr(string haystack, string needle) {
        lli n=haystack.size();
        lli m=needle.size();
    
        if(m>n) return -1;  
        
        lli maxsize1=1;
        lli maxsize2=1;
        
        for(lli i=0;i<m;i++){  
            maxsize1=(maxsize1*coef1)%prime1;
            maxsize2=(maxsize2*coef2)%prime2;
        }
        
        pair<lli,lli> hash_needle=calchash(needle,m);
        pair<lli,lli> hash_hay={0,0};


        for(lli i=0;i<=n-m;i++){
            if(i==0){
                hash_hay=calchash(haystack,m);
            }
            else{
                hash_hay.first=(hash_hay.first*coef1)%prime1;
                hash_hay.first=((hash_hay.first-(haystack[i-1]-'a')*maxsize1%prime1)+prime1)%prime1;
                hash_hay.first=(hash_hay.first+(haystack[i+m-1]-'a'))%prime1;
                
                hash_hay.second=(hash_hay.second*coef2)%prime2;
                hash_hay.second=((hash_hay.second-(haystack[i-1]-'a')*maxsize2%prime2)+prime2)%prime2;
                hash_hay.second=(hash_hay.second+(haystack[i+m-1]-'a'))%prime2;


                
            }
            if(hash_hay==hash_needle)return i;

        }
        return -1;
    }
};