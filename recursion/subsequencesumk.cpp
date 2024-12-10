#include<iostream>
using namespace std;
int n;
void findtarget(vector<int> v,int i,vector<int> ans,int sum, int target){
    if(i==n){
        if(sum==target){
            for(int i=0;i<ans.size();i++){
                cout<<ans[i];
            }
            cout<<endl;
        }
        
        return;
    }
    ans.push_back(v[i]);
    sum+=v[i];
    findtarget(v,i+1,ans,sum,target);
    ans.pop_back();
    sum-=v[i];
    findtarget(v,i+1,ans,sum,target);
}
int main(){

    cin>>n;
    vector<int> v;
    vector<int> ans;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    int target;
    cin>>target;
    findtarget(v,0,ans,0,target);
    return 0;
}