#include<bits/stdc++.h>
using namespace std;
//CODE TO MERGE TWO BST

/*In this code we are given two bst which are to be merged to form a new
bst
Here we will find inorder of both bst which will be sorted.
now we will merge these two sorted inorder to form a new inorder
Now using this new inorder will construct a balanced binary search tree
using the code we learned earlier */
class node
{
    public:
    int data;
    node * left;
    node* right;
    node()
    {
        data=-1;
        left=NULL;
        right=NULL;
    }
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }

};
node* balancedbst(vector<int> &v,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid=(s+e)/2;
    node* root=new node(v[mid]);
    root->left=balancedbst(v,s,mid-1);
    root->right=balancedbst(v,mid+1,e);
    return root;

}
node* buildbst(node* root,int d)
{
    if(root==NULL)
    {
        root=new node(d);
        return root;
    }
    if(root->data>d)
    {
        root->left=buildbst(root->left,d);
    }
    else
    {
        root->right=buildbst(root->right,d);
    }
    return root;
}
void input(node* &root)
{
    int d;
    cin>>d;
    while(d!=-1)
    {
        root=buildbst(root,d);
        cin>>d;
    }
}
void inorder(node* root,vector<int> &v)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
void mergeit(vector<int> &v,vector<int>v1,vector<int>v2)
{
    int n1=v1.size();
    int n2=v2.size();
    int i=0;
    int j=0;
    while(i<n1 && j<n2)
    {
        if(v1[i]<v2[j])
        {
            v.push_back(v1[i]);
            i++;

        }
        else
        {
            v.push_back(v2[j]);
            j++;
        }
    }

    while(i<n1)
    {
        v.push_back(v1[i]);
        i++;
    }
    while(j<n2)
    {
        v.push_back(v2[j]);
        j++;
    }

}
void inorderasli(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorderasli(root->left);
    cout<<root->data<<" ";
    inorderasli(root->right);
}
int main()
{
    node* root1=NULL;
    cout<<"Enter the values in the first bst :"<<endl;
    input(root1);
    node* root2=NULL;
    cout<<"Enter the value in the second bst :"<<endl;
    input(root2);


    //5 1 10 -1 20 15 25 -1

    vector<int>v1;
    vector<int>v2;

    inorder(root1,v1);
    inorder(root2,v2);

    cout<<endl;
    for(int i=0;i<v1.size();i++)
        cout<<v1[i]<<" ";
    cout<<endl;
    for(int i=0;i<v2.size();i++)
        cout<<v2[i]<<" ";
    cout<<endl;

    vector<int> v;
    mergeit(v,v1,v2);


    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";

    }
    cout<<endl;
    cout<<"Merged bst is ::"<<endl;
    int s=v.size();
    node* root=balancedbst(v,0,s-1);
    inorderasli(root);




    return 0;
}
