//Longest bitonic subsequence is the subsequence which can be strictly increasing, strictly decreasing or strictly 
//increasing then decreasing
//EG-: 123454321, 1243679421, 1234567, 654321 are all bitonic subsequences
//Approach- We'll calculate max lis length for each index from both left and right side of the array and add the value 
//for each index - 1 (to remove common element) to find the length of bitonic subsequence for current element as peak element.
//We'll do calculations for each index and calculate the value for all and our maximum value ot of each element will be the answer
#include<bits/stdc++.h>
using namespace std;


int longestBitonicSubsequence(vector<int>& arr, int n)
{
	// Write your code here.
	vector<int> dp1(n,1);
	vector<int> dp2(n,1);

	for(int i=0;i<n;i++){                           //calcuting lis length from left side for each index
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j] && 1+dp1[j]>dp1[i]){
				dp1[i]=1+dp1[j];
			}
		}
	}

	reverse(arr.begin(),arr.end());
	for(int i=0;i<n;i++){                              //calcuting lis length from right side for each index
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j] && 1+dp2[j]>dp2[i]){
				dp2[i]=1+dp2[j];
			}
		}
	}
	reverse(dp2.begin(),dp2.end());

	int ans=0;
	for(int i=0;i<n;i++){
		ans=max(ans,dp1[i]+dp2[i]-1);                   
	}
	return ans;

}



//better approach nlogn 

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums1) {
        // code here
        vector<int> insertedat1(n);
        vector<int> insertedat2(n);
        
        vector<int> v1;
        vector<int> v2;
        
        
        for(int i=0;i<n;i++){
            if(v1.size()==0){
                v1.push_back(nums1[i]);
                insertedat1[i]=v1.size();
            }
            else if(v1.back()<nums1[i]){
                v1.push_back(nums1[i]);
                insertedat1[i]=v1.size();
            }
            else{
                auto it=lower_bound(v1.begin(),v1.end(),nums1[i]);
                *it=nums1[i];
                insertedat1[i]=it-v1.begin()+1;
            }
        }
      
        reverse(nums1.begin(),nums1.end());
        for(int i=0;i<n;i++){
            if(v2.size()==0){
                v2.push_back(nums1[i]);
                insertedat2[i]=v2.size();
            }
            else if(v2.back()<nums1[i]){
                v2.push_back(nums1[i]);
                insertedat2[i]=v2.size();
            }
            else{
                auto it=lower_bound(v2.begin(),v2.end(),nums1[i]);
                *it=nums1[i];
                insertedat2[i]=it-v2.begin()+1;
            }
        }
        reverse(insertedat2.begin(),insertedat2.end());
   
        int ans=0;
  
        for(int i=0;i<n;i++){
            if((insertedat1[i]>1) && (insertedat2[i]>1)){
                ans=max(ans,insertedat1[i]+insertedat2[i]-1);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
    }
}

// } Driver Code Ends