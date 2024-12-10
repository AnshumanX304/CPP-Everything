
//This question is similar to its first part except for the fact that the first and last index of the array are now considered
//adjacent i.e. it is a circular array

//Intuation-: We just don't need 1st and last index element to be added up so we will first take an array temp1
//            having no first element and another array temp2 two having no last element 
//            In this way we can easily exclude the first and last element now we will simply apply our previous approach in 
//            both the arrays and max of both the answers obtained will be our final answer.



//LeetCode problem link-: https://leetcode.com/problems/house-robber-ii/description/





#include<bits/stdc++.h>
using namespace std;



// int maxSum(int idx,vector<int> &nums,vector<int> &dp){       //dp with memoisation
//     if(idx==0)return nums[0];
//     if(idx<1)return 0;

//     if(dp[idx]!=-1)return dp[idx];

//     int pick=nums[idx]+maxSum(idx-2,nums,dp);
//     int notpick=maxSum(idx-1,nums,dp);
//     return dp[idx]=max(pick,notpick);
// }





int maxSum(int idx,vector<int> &nums,vector<int> &dp){            //dp with space optimisation

    int n=nums.size();
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

    return cur;

}




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
    if(n==1){
        cout<<nums[0]<<endl;
        return 0;
    }

    vector<int> temp1,temp2;
    for(int i=0;i<n;i++){
        if(i!=0)temp1.push_back(nums[i]);
        if(i!=n-1)temp2.push_back(nums[i]);
    }
    cout<<max(maxSum(n-2,temp1,dp),maxSum(n-2,temp2,dp))<<endl;
    return 0;

}