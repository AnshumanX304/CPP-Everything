#include<bits/stdc++.h>
using namespace std;

//In this approach we are just checking if the new element we traverse is greater than the previous element and if it is greater
//then we simply put it in the array and if not we find the place using binary serch to replace it with suitable element in the array.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[idx]=nums[i];
            }
        }
        return temp.size();
    }
};