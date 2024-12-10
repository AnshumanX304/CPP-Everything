#include<bits/stdc++.h>
using namespace std;
#define lli long long int
    
    
lli base=27;
lli mod=1e9+7;

vector<lli> forward_hash;
vector<lli> backward_hash;
vector<lli> power;

lli binpow(lli a, lli b) {
    lli res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

lli modinverse(lli num){
    return binpow(num,mod-2);
}

void calchash(string &s){
        lli n=s.size();
        forward_hash.resize(n);
        backward_hash.resize(n);
        power.resize(n);

        power[0]=1;
        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*base)%mod;
        }

        forward_hash[0]=((lli)(s[0]-'a')*power[0])%mod;

        for(int i=1;i<n;i++){
            forward_hash[i]=(forward_hash[i-1]+((lli)(s[i]-'a')*power[i])%mod)%mod;
        }
        reverse(s.begin(),s.end());

        backward_hash[0]=((lli)(s[0]-'a')*power[0])%mod;

        for(int i=1;i<n;i++){
            backward_hash[i]=(backward_hash[i-1]+((lli)(s[i]-'a')*power[i])%mod)%mod;
        }
    }


    int getforwardhash(int l,int r){
        lli hashval=forward_hash[r];
        if(l-1>=0){
            hashval=((hashval-forward_hash[l-1])%mod+mod)%mod;
        }
        return hashval;
    }


    int getbackwardhash(int l,int r){
        lli n=backward_hash.size();
        lli newl=n-r-1;
        lli newr=n-l-1;

        lli hashval=backward_hash[newr];
        if(newl-1>=0){
            hashval=((hashval-backward_hash[newl-1])%mod+mod)%mod;
        }

        return hashval;

        
    }

    
    bool ispalindrome(int l,int r){ 

        int forward=getforwardhash(l,r);
        int backward=getbackwardhash(l,r);
        lli n=forward_hash.size();

        lli factor_forward=power[l];
        lli factor_backward=power[n-r-1];

        lli new_forward=(forward*modinverse(factor_forward))%mod;
        lli new_backward=(backward*modinverse(factor_backward))%mod;

        return new_forward==new_backward;
    }