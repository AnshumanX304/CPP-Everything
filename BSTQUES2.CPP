#include<bits/stdc++.h>
using namespace std;
//build a balanced bst from inorder sequence
class node
{   public:
    int data;
    node* left;
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

node* buildbst(node* root,int d)
{
    if(root==NULL)
    {
        root=new node(d);
        return root;
    }
    if(d>root->data)
    {
        root->right=buildbst(root->right,d);
    }
    else
        root->left=buildbst(root->left,d);

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
void levelorder(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp!=NULL)
        {
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        else
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }

    }
}
node* buildbalancedbst(vector<int> &v,int s,int e)
{
    if(s>e)
    {
        return NULL;
    }
    int mid=(s+e)/2;
    node* root=new node(v[mid]);
    root->left=buildbalancedbst(v,s,mid-1);
    root->right=buildbalancedbst(v,mid+1,e);
    return root;




}
void inorder(node* root,vector<int> &v)
{
    if(root==NULL)
    {
        return ;
    }
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
int main()
{
    node* root=NULL;
    cout<<"Enter the data in the bst:"<<endl;
    input(root);
    cout<<"The bst has been build !"<<endl;

    cout<<"The bst in levelorder traversal is -"<<endl;
    levelorder(root);
    //8 6 4 3 1 10 -1
    vector<int> v;
    inorder(root,v);
    int e=v.size();

    root=buildbalancedbst(v,0,e-1);
    cout<<"Balanced bst of given binary tree is :"<<endl;
    levelorder(root);

    return 0;
}
