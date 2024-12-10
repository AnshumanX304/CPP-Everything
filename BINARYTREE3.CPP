#include<bits/stdc++.h>
using namespace std;
class node
{   public:
    int data;
    node* left;
    node* right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
    node()
    {
        data=-1;
        left=NULL;
        right=NULL;
    }

};
node* buildlevelorder(node* root)
{
   int data;
   cout<<"Enter the data for root ::"<<endl;
   cin>>data;
   root=new node(data);
   queue<node*> q;
   q.push(root);
   while(!q.empty())
   {
       node* temp=q.front();
       q.pop();
       int leftnode;
       cout<<"Enter the data for left of "<<temp->data<<endl;
       cin>>leftnode;
       if(leftnode!=-1)
       {
            temp->left=new node(leftnode);
            q.push(temp->left);
       }
       int rightnode;
       cout<<"Enter the data for right of "<<temp->data<<endl;
       cin>>rightnode;
       if(rightnode!=-1)
       {
            temp->right=new node(rightnode);
            q.push(temp->right);
       }
    }
    return root;
}
void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


node* mapping(node* root,int target,map<node*,node*> &nodetoparent)
{
    queue<node*> q;
    q.push(root);
    node* ans=NULL;
    nodetoparent[root]=NULL;
    while(!q.empty())
    {
        node* frontele=q.front();
        q.pop();
        if(frontele->data=target)
            ans=frontele;

        if(frontele->left)
        {
            q.push(frontele->left);
            nodetoparent[frontele->left]=frontele;
        }

        if(frontele->right)
        {
            q.push(frontele->right);
            nodetoparent[frontele->right]=frontele;
        }
    }
    return ans;
}
int burntree(node* target,map<node*,node*> &nodetoparent)
{
    map<node*,bool> m;
    queue<node*> q;
    int ans=0;
    q.push(target);
    m[target]=1;
    while(!q.empty())
    {   bool flag=0;
        int size=q.size();
        for(int i=0;i<size;i++)
        {
            node* frontele=q.front();
            q.pop();

            if(frontele->left && !m[frontele->left])
            {
                flag=1;
                m[frontele]=1;
                q.push(frontele->left);

            }
            if(frontele->right && !m[frontele->right])
            {
                flag=1;
                m[frontele]=1;
                q.push(frontele->right);

            }
            if(nodetoparent[frontele] && !m[nodetoparent[frontele]])
            {
                flag=1;
                m[nodetoparent[frontele]]=1;
                q.push(nodetoparent[frontele]);

            }

        }
        if(flag==1)
            ans++;
    }
    return ans;
}
int main()
{   //1 2 3 -1 -1 -1 -1
    node* root=NULL;
    root=buildlevelorder(root);
    map<node*,node*>nodetoparent;
    int targetele;
    cout<<"Enter the target node ::"<<endl;
    cin>>targetele;
    node* target=mapping(root,targetele,nodetoparent);
    cout<<target->data<<endl;

    cout<<"Minimum time required is ::"<<endl;
    cout<<burntree(target,nodetoparent);

    return 0;

}
