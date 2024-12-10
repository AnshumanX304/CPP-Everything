#include<iostream>
using namespace std;
int n;
bool findtarget(vector<int> v,int i,vector<int> ans,int sum, int target){
    if(i==n){
        if(sum==target){
            for(int i=0;i<ans.size();i++){
                cout<<ans[i];
            }
            cout<<endl;
            return true;
        }
        
        return false;
    }
    ans.push_back(v[i]);
    sum+=v[i];
    int flag1=findtarget(v,i+1,ans,sum,target);
    if(flag1==true){
        return true;
    }
    ans.pop_back();
    sum-=v[i];
    int flag2=findtarget(v,i+1,ans,sum,target);
    if(flag2==true){
        return true;
    }
    return true;
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