#include<iostream>
using namespace std;
class bt
{   public:
    int val;
    bt * left;
    bt * right;
    bt(int a)
    {
        val=a;
        left=NULL;
        right=NULL;
    }
    bt()
    {
        left=NULL;
        right=NULL;
    }
    void preorder(bt *root)
    {
        if(root==NULL)
        {
            return;
        }
        cout<<root->val;
        preorder(root->left);
        preorder(root->right);
    }
    void inorder(bt *root)
    {
        if(root==NULL)
            return;

        inorder(root->left);
        cout<<root->val;
        inorder(root->right);

    }
    void postorder(bt *root)
    {
        if(root==NULL)
        {
            return ;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->val;
    }
};
int main()
{
    bt *obj=new bt(1);
    obj->left=new bt(2);
    obj->right=new bt(3);
    obj->left->left=new bt(4);
    obj->left->right=new bt(5);
    obj->right->left=new bt(6);
    obj->right->right=new bt(7);

    bt temp;
    temp.preorder(obj);
    cout<<endl;
    temp.inorder(obj);
    cout<<endl;
    temp.postorder(obj);

    return 0;

}
