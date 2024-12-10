#include<bits/stdc++.h>
using namespace std;
//MORRIS TRAVERSAL
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
void inordermorristraversal(node *root)
{
    vector<int> inorder;
    node* curr=root;
    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
            inorder.push_back(curr->data);
            curr=curr->right;
        }
        else{
            node* prev=curr->left;
            while(prev->right && prev->right!=curr)
            {
                prev=prev->right;
            }
            if(prev->right==NULL)
            {
                prev->right=curr;
                curr=curr->left;
            }
            else
            {
                prev->right=NULL;
                inorder.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
    for(int i=0;i<inorder.size();i++)
    {
        cout<<inorder[i]<<" ";
    }
}
void preordermorristraversal(node*root)
{
    node* curr=root;
    vector<int>preorder;
    while(curr!=NULL)
    {
        if(curr->left==NULL)
        {
            preorder.push_back(curr->data);
            curr=curr->right;
        }
        else
        {
            node* prev=curr->left;
            if(prev->right && prev->right!=curr)
            {
                prev=prev->right;
            }
            if(prev->right==NULL)
            {
                prev->right=curr;
                preorder.push_back(curr->data);
                curr=curr->left;
            }
            if(prev->right==curr)
            {
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
    for(int i=0;i<preorder.size();i++)
    {
        cout<<preorder[i]<<" ";
    }

}
node* levelorder(node *root)
{
    queue<node*> q;
    cout<<"Enter the data in the node :"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        cout<<"Enter the data to the left of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1)
        {
            temp->left=new node(leftdata);
            q.push(temp->left);
        }
        cout<<"Enter the data in the right of the "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1)
        {
            temp->right=new node(rightdata);
            q.push(temp->right);
        }
    }
    return root;
}
int main()
{
    node* root=NULL;
    root=levelorder(root);
    inordermorristraversal(root);
    cout<<endl;
    preordermorristraversal(root);
    return 0;
}
