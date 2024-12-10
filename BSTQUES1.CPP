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
//QUES1-> To find if the given tree is a bst or not
bool isbst(node* root,int mini,int maxi)
{
    if(root==NULL)
        return true;

    if(root->data>=mini && root->data<=maxi)
    {
        bool left=isbst(root->left,mini,root->data);
        bool right=isbst(root->right,root->data,maxi);
        return right&&left;
    }
    else
        return false;
}
//QUES2-> To find the kth smallest element in the bst
int solve(node* root,int &i,int k)
{
    if(root==NULL)
        return -1;
    int left=solve(root->left,i,k);
    if(left!=-1)
        return left;
    i++;
    if(i==k)
        return root->data;

    return solve(root->right,i,k);



}
// QUES3-> Inorder predecessor and inorder successor
//process 1-> In this we'll put all the elements of the tree in an array in inorder
            //manner and then we'll find the element whose predecessor and successor is to be found
            //and print the element before and after it to get the predecessor and successor of it

//process2-> In this we find the element by simple traversal
           //and the greatest element in its left subtree is its inorder predecessor and the smallest one to the
           //right subtree is the inorder successor
int minval(node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root->data;
}
int maxval(node* root)
{
    while(root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
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

void predsucc(node* root,int key)
{
    if(root->data==key)
    {
        cout<<"Inorder predecessor is :"<<endl;
        cout<<maxval(root->left);
        cout<<endl;
        cout<<"Inorder successor is :"<<endl;
        cout<<minval(root->right);
        return;
    }
    if(key>root->data)
    {
        predsucc(root->right,key);
    }
    else
        predsucc(root->left,key);
}
node* buildbst(node* root,int d)
{
    if(root==NULL)
    {
        node* root=new node(d);
        return root;
    }
    if(d>root->data)
    {
        root->right=buildbst(root->right,d);
    }
    else
    {
        root->left=buildbst(root->left,d);
    }
    return root;
}
void input(node* &root)
{
    cout<<"Enter the data ::"<<endl;
    int d;
    cin>>d;
    while(d!=-1)
    {
        root=buildbst(root,d);
        cin>>d;
    }
}
void flattenbst(node* root,vector<int> &in) //for creating the vector containing elements of bst in inorder
{                                           //which will be converted to linked list later
    if(root==NULL)
    {
        return ;
    }
    flattenbst(root->left,in);
    in.push_back(root->data);
    flattenbst(root->right,in);
}
int main()
{
    node* root=NULL;
    input(root);
    //11 8 13 7 9 -1
    cout<<endl;
    inorder(root);
    cout<<endl;
    cout<<isbst(root,INT_MIN,INT_MAX)<<endl;
    predsucc(root,11);
    cout<<endl;
    int i=0;
    cout<<solve(root,i,3);

    //linked formation starts here
    vector<int> v;
    flattenbst(root,v);
    cout<<endl;
    node* temproot=new node(v[0]); //root of the new linked list
    node* temp=temproot;
    for(int i=0;i<v.size()-1;i++)
    {
        temp->right=new node(v[i+1]); //linked list creation
        temp=temp->right;
    }
    temp->right=NULL;
    temp=temproot;

    while(temp!=NULL)         //printing linked list
    {
        cout<<temp->data<<" ";
        temp=temp->right;
    }


    return 0;

}
