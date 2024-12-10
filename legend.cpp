/*#include<iostream>
#include<queue>
using namespace std;
class node
{   public:
    int val;
    node* left;
    node* right;
    node()
    {
        left=NULL;
        right=NULL;
    }
    node(int a)
    {
        val=a;
        left=NULL;
        right=NULL;
    }
    void inorder(node*ptr)
    {
        if(ptr==NULL)
        {
            return;
        }
        inorder(ptr->left);
        cout<<ptr->val;
        inorder(ptr->right);
    }
    void levelorder(node* ptr)
    {
        if(ptr==NULL)
            return;
        queue<node*> q;
        q.push(ptr);
        q.push(NULL);
        while(!q.empty())
        {
            node* f=q.front();
            q.pop();

            if(f!=NULL)
            {
                cout<<f->val<<" ";
                if(f->left!=NULL)
                {
                    q.push(f->left);
                }
                if(f->right!=NULL)
                {
                    q.push(f->right);
                }
            }
            else if(!q.empty())
            {
                q.push(NULL);
            }
        }

    }
};
int search(int inorder[],int start,int end,int curr)
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
    node*ptr=new node(curr);
    if(start==end)
    {
        return ptr;
    }
    int pos=search(inorder,start,end,curr);
    ptr->left=buildtree(preorder,inorder,start,pos-1);
    ptr->right=buildtree(preorder,inorder,pos+1,end);
    return ptr;


}
node *buildpost(int postorder[],int inorder[],int start,int end)
{
    static int idx=end;
    if(start>end)
    {
        return NULL;
    }
    int curr=postorder[idx];
    idx--;
    node *ptr=new node(curr);
    if(start==end)
    {
        return ptr;
    }
    int pos=search(inorder,start,end,curr);
    ptr->right=buildpost(postorder,inorder,pos+1,end);
    ptr->left=buildpost(postorder,inorder,start,pos-1);
    return ptr;
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
    node*ptr1=buildpost(postorder,inorder,0,6);
    obj.inorder(ptr1);
    cout<<endl;
    obj.levelorder(ptr);
    return 0;
}
*/
#include<iostream>
using namespace std;
class node
{
    int val;
    node* left;
    node* right;
    node()
    {
        left=NULL;
        right=NULL;
    }
    node(int a)
    {
        val=a;
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
        cout<<ptr->val;
        inorder(ptr->right);
    }
};
node* buildtree(int preorder[],int inorder[],int start,int end)
{
    static int idx=0;
    
}
