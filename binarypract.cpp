#include<iostream>
using namespace std;
class node
{   public:
    int data;
    node* left=NULL;
    node* right=NULL;
    node()
    {
        left=NULL;
        right=NULL;
    }
    node(int val)
    {
        data=val;
        left=NULL;
        right==NULL;
    }
    void inorder(node* ptr)
    {
        if(ptr==NULL)
        {
            return;
        }
        inorder(ptr->left);
        cout<<ptr->data<<" ";
        inorder(ptr->right);

    }
    void postorder(node *ptr)
    {
        if(ptr==NULL)
        {
            return ;
        }
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->data<<" ";
    }
};
int index(int inorder[],int start,int end,int curr)
{
    for(int i=start;i<end;i++)
    {
        if(inorder[i]==curr)
        {
            return i;
        }
    }
}
node* buildtree(int preorder[],int inorder[],int start,int end)
{
    static int idx=0;
    if(start>end)
        return NULL;
    int curr=inorder[idx];
    node* ptr=new node(curr);
    
    idx++;
    int pos=index(inorder,start,end,curr);
    if(start==end)
        return ptr;
    ptr->left=buildtree(preorder,inorder,start,pos-1);
    ptr->right=buildtree(preorder,inorder,pos+1,end);
    return ptr;
    
}
int main()
{
    int preorder[]={1,2,4,5,3,6,7};
    int inorder[]={4,2,5,1,6,3,7};
    node obj;
    node*ptr=buildtree(preorder,inorder,0,6);
    obj.inorder(ptr);
    cout<<endl;
    
    obj.postorder(ptr);
    return 0;
}
