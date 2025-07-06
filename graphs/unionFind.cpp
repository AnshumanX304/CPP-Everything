#include<iostream>
using namespace std;
class disjointSet{
    private:
    vector<int> rank;
    vector<int> parent;
    vector<int> size;
    int comp;
    public:
    disjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        for(int i=0;i<=n;i++){
            parent[i]=1;
        }
        this->comp=n;
    }

    int findUParent(int node){
        if(parent[node]==node)return node;
        return parent[node]=findUParent(parent[node]);   //with path compression
        // return findUParent(parent[node]);    // without path compression 
    }

    void unionByRank(int node1,int node2){
        int p_node1=findUParent(node1);
        int p_node2=findUParent(node2);
        if(p_node1==p_node2)return;
        // else{
        //     parent[node1]=node2;       //these commented lines represent normal union without using rank or size but path 
        // }                               //compression is still used 
                                      
        
        if(rank[p_node1]>rank[p_node2]){
            parent[p_node2]=p_node1;

        }
        else if(rank[p_node2]>rank[p_node1]){
            parent[p_node1]=p_node2;
        }
        else{
            parent[p_node2]=p_node1;
            rank[p_node1]++;
        }
        comp--;
    }

    void unionBySize(int node1, int node2){
        int p_node1=findUParent(node1);
        int p_node2=findUParent(node2);
        if(p_node1==p_node2)return;

        if(size[p_node2]<size[p_node1]){
            parent[p_node2]=p_node1;
            size[p_node1]+=size[p_node2];
        }
        else{
            parent[p_node1]=p_node2;
            size[p_node2]+=size[p_node1];
        }

    }

    int get_comp(){
        return this->comp;
    }

};

int main(){
    disjointSet ds(7);
    ds.unionByRank(1, 2); 
    ds.unionByRank(2, 3); 
    ds.unionByRank(4, 5); 
    ds.unionByRank(6, 7); 
    ds.unionByRank(5, 6); 
    // if 3 and 7 same or not 
    if(ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    ds.unionByRank(3, 7); 

    if(ds.findUParent(3) == ds.findUParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 
	return 0;
}


/* syntax, variables, data type, list, dictionary, loops,  */
