#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node*left;
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
    void postorder(node* ptr)
    {
        if(ptr==NULL);
        {
            return;
        }
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->data<<" ";

    }
};
int index(int inorder[],int curr,int start,int end)
{
    for(int i=start;i<end;i++)
    {
        if(inorder[i]==curr)
            return i;
    }
}
node*buildtree(int preorder[],int inorder[],int start,int end)
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
    int pos=index(inorder,curr,start,end);
    ptr->left=buildtree(preorder,inorder,start,pos-1);
    ptr->right=buildtree(preorder,inorder,pos+1,end);
    return ptr;

}
int main()
{
    node obj;
    int preorder[]={1,2,4,5,3,6,7};
    int inorder[]={4,2,5,1,6,3,7};
    node* ptr=buildtree(preorder,inorder,0,6);
    obj.inorder(ptr);
    obj.postorder(ptr);
    return 0;


}