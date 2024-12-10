
//--------------------------------------------------------------------------------------------------------------------------------------//

//LeetCode problem name-: House Robber


//DP Solution using recursion + memoisation

// #include<bits/stdc++.h>
// using namespace std;

// int maxSum(int idx,vector<int> &nums,vector<int> &dp){
//     if(idx==0)return nums[0];
//     if(idx<1)return 0;

//     if(dp[idx]!=-1)return dp[idx];

//     int pick=nums[idx]+maxSum(idx-2,nums,dp);
//     int notpick=maxSum(idx-1,nums,dp);
//     return dp[idx]=max(pick,notpick);
// }

// int main(){
//     int n;
//     cout<<"Enter the number of elements"<<endl;
//     cin>>n;
//     vector<int> nums(n);
//     vector<int> dp(n,-1);
//     cout<<"Enter the elements"<<endl;
//     for(int i=0;i<n;i++){
//         cin>>nums[i];
//     }
//     cout<<maxSum(n-1,nums,dp)<<endl;
//     return 0;

// }


//-----------------------------------------------------------------------------------------------------------------------------------------//



// DP Solution using tabulation
// #include<bits/stdc++.h>
// using namespace std;



// int main(){
//     int n;
//     cout<<"Enter the number of elements"<<endl;
//     cin>>n;
//     vector<int> nums(n);
//     vector<int> dp(n,-1);
//     cout<<"Enter the elements"<<endl;
//     for(int i=0;i<n;i++){
//         cin>>nums[i];
//     }
//     dp[0]=nums[0];
//     for(int i=1;i<n;i++){

//         int pick=nums[i];
//         if(i>1)pick+=dp[i-2];
//         int notpick=dp[i-1];

//         dp[i]=max(pick,notpick);

//     }

//     cout<<dp[n-1]<<endl;
//     return 0;

// }



//--------------------------------------------------------------------------------------------------------------------------------------//


//DP using Space Optimisation

#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    vector<int> nums(n);
    vector<int> dp(n,-1);
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int prev=nums[0];
    int prev2=0;
    int cur;
    for(int i=1;i<n;i++){
        int pick=nums[i];
        if(i>1)pick+=prev2;

        int notpick=prev;
        cur=max(pick,notpick);
        prev2=prev;
        prev=cur;

        
    }

    cout<<cur<<endl;
    return 0;

}


//------------------------------------------------------------------------------------------------------------------------------------//