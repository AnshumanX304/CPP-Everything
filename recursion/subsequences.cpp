#include<iostream>
using namespace std;
int n;
void subsequence(string s,int i,vector<char> v){
    if(i==n){
       for(int i=0;i<v.size();i++){
        cout<<v[i];
        }
       cout<<endl;
        return;
    }
    v.push_back(s[i]);
    subsequence(s,i+1,v);
    v.pop_back();
    subsequence(s,i+1,v);

    
}
int main(){
    string s;
    vector<char> v;
    
    cin>>s;
    n=s.size();
    subsequence(s,0,v);
    return 0;
}