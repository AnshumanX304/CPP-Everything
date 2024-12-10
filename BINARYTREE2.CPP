#include<bits/stdc++.h>
using namespace std;
//creating tree using inorder and preorder
/*node* inorderandpreorder(int in[],int pre[],int index,int inorderstart,int inorderend,int n)
{
    if(index>=n || inorderstart>inorderend)
        return NULL;
    int ele=pre[index++];
    node* root=new node(ele);
    int pos=findpos(in,ele,n);

    root->left=inorderandpreorder(in,pre,index,inorderstart,pos-1,n);
    root->right=inorderandpreorder(in,pre,index,pos+1,inorderend,n);
    return root;
}

*/
class node
{   public:
    int val;
    node* left;
    node* right;
    node(int data)
    {
        val=data;
        left=NULL;
        right=NULL;
    }
    node()
    {
        val=-1;
        left=NULL;
        right=NULL;
    }

};
int findpos(int in[],int ele,int n)
{
    for(int i=0;i<n;i++)
    {
        if(in[i]==ele)
            return i;
    }
}
void inordertraversal(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inordertraversal(root->left);
    cout<<root->val<<" ";
    inordertraversal(root->right);
}
node* inandpre(int in[],int pre[],int &index,int start,int end,int n)
{
    if(index>=n || start>end)
    {
        return NULL;
    }
    int ele=pre[index];
    index++;
    node*root=new node(ele);
    int pos=findpos(in,ele,n);

    root->left=inandpre(in,pre,index,start,pos-1,n);
    root->right=inandpre(in,pre,index,pos+1,end,n);
    return root;
}
node* inandpost(int in[],int post[],int &index,int start,int end,int n)
{
    if(index<

         0 || start>end)
    {
        return NULL;
    }
    int ele=post[index];
    --index;
    node*root=new node(ele);
    int pos=findpos(in,ele,n);
    root->right=inandpost(in,post,index,pos+1,end,n);
    root->left=inandpost(in,post,index,start,pos-1,n);

}
int main()
{
    int inorder[]={4,2,5,1,6,3,7};
    int preorder[]={1,2,4,5,3,6,7};
    int postorder[]={4,5,2,6,7,3,1};
    int index=6;
    //node* root=inandpre(inorder,preorder,index,0,6,7);
    node*root=inandpost(inorder,postorder,index,0,6,7);
    inordertraversal(root);
    return 0;

}
