//JAI SHREE RAM 

#include<bits/stdc++.h>
using namespace std;


#define ld long double
#define ll long long 
#define lli long long int 
#define vi vector<int>
#define vl vector<long long int>
#define pb push_back
#define vpi vector<pair<int,int>>
#define vpl vector<pair<long long int, long long int>>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define repl(i,a,n) for(lli i=a;i<n;i++)
#define mpi map<int,int>
#define mpl map<lli,lli>
#define maxe max_element
#define mine min_element
#define pie 1.0l*acos(-1)

string getBinary(int n) {
    bitset<64> b(n);
    return b.to_string();
}



        // lli n;
        // cin>>n;
        // vl v(n);
        // repl(i,0,n){
        //     cin>>v[i];
        // }
        
        // vector<vector<lli>> bitmap(n,vector<lli>(32));
        // repl(i,0,n){
        //     lli temp=v[i];
        //     lli mask=1;
        //     lli pos=0;
        //     while(temp!=0){
        //         if((temp&mask)==0){
        //             bitmap[i][pos]=0;
        //         }
        //         else{
        //             bitmap[i][pos]=1;
        //         }  
        //         temp>>=1;
        //         pos++;
        //     }  
        // }




//FOR USING ORDERED_SET POLICY BASED DATA STRUCTURE IN C++ AS oset
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;




//for multiplying and moduling values in a same variable using modulo
// ans=(ans+1LL*ans*len) % mod; 




//*next(s.begin()+pos-1)   to get the element at given position pos in a set

int mod=1e9+7;
//modulous of negative and positive number is (b + (a % b)) % b where b is +ive 
//and a is -ive


//ceil(a/b)=(a+b-1)/b or ceil((double(a))/double(b)) will give accurate result if a and b are int type
//can use this function as well
lli ceil(lli a,lli b){
    return ceil((double(a))/double(b));
}
// or this function for large values of a and b

// int ceil2(int a, int b) {
//     if (a == 0) return 0;
//     return (a - 1)/b + 1;
// }


class SegmentTree{
    public:
    int n;
    vector<int> st;
    SegmentTree(int n){
        this->n = n;
        st.resize(4*n);
    }

    int op(int a,int b){
        return a+b; //this is where you do range query operations
    }
    void build(int start,int end,int node,vector<int> &v){
        if(start==end){
            st[node]=v[start];
            return;
        }
        int mid=(start+end)/2;
        build(start,mid,2*node+1,v);
        build(mid+1,end,2*node+2,v);
        st[node]=op(st[2*node+1],st[2*node+2]);
    }

    int query(int start,int end,int l,int r,int node){
        if(start>r || end<l)return 0;

        if(start>=l && end<=r)return st[node];

        int mid=(start+end)/2;

        int left=query(start,mid,l,r,2*node+1);
        int right=query(mid+1,end,l,r,2*node+2);

        return op(left,right);
    }

    void update(int start,int end,int node,int idx,int val){
        if(start==end){
            st[node]=val;
            return;
        }
        int mid=(start+end)/2;

        if(idx<=mid){
            update(start,mid,node*2+1,idx,val);
        }
        else{
            update(mid+1,end,node*2+2,idx,val);

        }
        st[node]=op(st[2*node+1],st[2*node+2]);
        return ;
    }


    void build(vector<int> &v){
        build(0,n-1,0,v);
    }
    int query(int left,int right){
        return query(0,n-1,left,right,0);
    }
    void update(int idx,int val){
        update(0,n-1,0,idx,val);
    }
};







// A modular inverse based solution to
// compute nCr % p
/* Iterative Function to calculate (x^y)%p
in O(log y) */

//Intution-: square the base and halve the exponent
unsigned long long power(unsigned long long x, 
                                  int y, int p)
{
    unsigned long long res = 1; // Initialize result
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0) 
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        x = (x * x) % p;
        y = y >> 1; // y = y/2
    }
    return res;
}
 
// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n,  
                                            int p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
unsigned long long nCrModPFermat(unsigned long long n,
                                 int r, int p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}


//For calculating powers of big numbers
long long binpow(long long n, long long p){
	long long res = 1;
	while(p) {
		if(p & 1) {
			res *= n;
			res %= mod;
		}
		p >>= 1;
		n *= n;
		n %= mod;
	}
	return res;
}
//while calculating values add mod and then do val%mod
//i.e   (val+mod)%mod  in order to avoid negative values


int myfloor(int a, int b) {
    if (a % b == 0) return (a / b);
    bool negative = (a < 0) ^ (b < 0);
    return a / b - negative;
}


//COMPARATOR FUNCTION FOR NORMAL ARRAYS
bool cmp(pair<int, int>a, pair<int, int>b) {    //comparator function to sort vector of pair in descending order as per first element 
	if (a.first == b.first)                      //and in descending order as per second element 
		return b.second > a.second;             //we can use  similar comparator function to decide sorting behaviour accordingly. 
	return a.first > b.first;
}

//COMPARATOR FUNCTION FOR PRIORITY QUEUE
// class Compare {                              //comparator function should be used as class template with priority queue 
//     public:
//        bool operator()(pair<int,int> below, pair<int,int> above)
//         {
//             if (below.first < above.first) {
//                 return true;
//             }
//             else if (below.first == above.first
//                      && below.second > above.second) {
//                 return true;
//             }
     
//             return false;
//         }
// };

// bool SieveOfEratosthenes(int n) 
// { 
//     bool prime[n + 1]; 
//     memset(prime, true, sizeof(prime)); 
//     for (int p = 2; p * p <= n; p++) { 
//         if (prime[p] == true) { 
//             for (int i = p * p; i <= n; i += p) 
//                 prime[i] = false; 
//         } 
//     } 
//     for (int p = 2; p <= n; p++) 
//         if (prime[p]) 
//             cout << p << " "; 
// } 


lli no_of_divisors(lli n){
    lli cnt = 0; 
    for (lli i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            if (n / i == i) 
                cnt++; 
            else 
                cnt = cnt + 2;  //two divisors n/i and i hence count=count+2
        } 
    } 
    return cnt; 
}


lli ncr(lli n,lli r)
{
    if(n<r)return 0;
    lli p=1,k=1;
    if(n-r<r)
        r=n-r;
 
    if(r!=0) {
        while(r){
            p*=n;
            k*=r;
            ll m=__gcd(p,k);
            p/=m;
            k/=m;
            n--;
            r--;
        }
    }
    else
        p=1;
        
   return p;
}
 

//an another way to find divisors is to take prime factors of a number and then apply formula 
//number of divisors=(a+1)*(b+1)*(c+1).......  (here a,b,c are number of occurances of prime numbers in prime factorization)

//do not follow this approach as it has higher time complexity so use previous method mentioned above

lli no_ofdivisors(lli n){
    vector<int>pf=prime_factorization(n);
    mpl m;
    repl(i,0,pf.size()){     //count the frequency of each element or prime factor
        m[pf[i]]++;
    }
    lli ans=1;
    for(auto&it:m){
        ans=ans*(it.second+1); 
    }
    return ans;
}



vector<int> prime_factorization(lli n){
    vector<int> prime_factors;

    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            prime_factors.pb(i);
            n/=i;
        }

    }
    if(n>1)prime_factors.pb(n);

    return prime_factors;
    
}

bool isvowel(char c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')return true;
    return false;
}


bool isprime(lli n){
    if(n<2)return false;
    if(n==2)return true;
    for(lli i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int fact(int num){
    if(num==1 || num==0){
        return 1;
    }
    
    return num*fact(num-1);
    
}







int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    lli t;
    cin>>t;
    while(t--){
        
        

    }
    
       
    return 0;
}


