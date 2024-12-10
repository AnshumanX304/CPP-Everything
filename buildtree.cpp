#include<iostream>
using namespace std;
class node
{   public:
    int data;
    node* left;
    node*right;
    node()
    {
        left=NULL;
        right=NULL;
    }
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
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
};
int index(int inorder[],int start,int end,int curr)
{
    for(int i=start;i<end;i++)
    {
        if(inorder[i]==curr)
            return i;
    }
}
node* buildtree(int preorder[],int inorder[],int start,int end)
{
    static int idx=0;
    if(start>end)
    {
        return NULL;
    }
    int curr=preorder[idx];
    idx++;
    node* ptr=new node(curr);
    if(start==end)
    {
        return ptr;
    }
    int pos=index(inorder,start,end,curr);
    ptr->left=buildtree(preorder,inorder,start,pos-1);
    ptr->right=buildtree(preorder,inorder,pos+1,end);
    return ptr;

     

}
node* buildorder(int postorder[],int inorder[],int start,int end)
{
    static int idx=end;
    if(start>end)
    {
        return NULL;
    }
    int val=postorder[idx];
    idx--;
    node* curr=new node(val);
    if(start==end)
    {
        return curr;
    }
    int pos=index(inorder,start,end,val);
    curr->right=buildorder(postorder,inorder,pos+1,end);
    curr->left=buildorder(postorder,inorder,start,pos-1);
    return curr;

    

}
int main()

{
    int inorder[]={4,2,5,1,6,3,7};
    int preorder[]={1,2,4,5,3,6,7};
    int postorder[]={4,5,2,6,7,3,1};
    node* ptr=buildtree(preorder,inorder,0,6);
    node obj;
    obj.inorder(ptr);
    cout<<endl;
    node*ptr1=buildorder(postorder,inorder,0,6);
    obj.inorder(ptr1);
    return 0;

}