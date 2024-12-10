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
void inorder(node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

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

void levelorder(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node*temp=q.front();
        q.pop();
        if(temp!=NULL)
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
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
bool search(node* root, int val)
{
    if(root->data==val)
    {
        return true;
    }
    if(val>root->data)
        return search(root->right,val);
    else
        return
        search(root->left,val);


    return false;
}
/*bool search(node* root,int data) //searching using iterative method
{
    node* temp=root;
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            return true;
        }
        if(temp->data>x)
        {
            temp=temp->left;
        }
        else
            temp=temp->right;
    }
    return false;
}*/
node* minvalue(node* root)
{
    node* temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
node* maxvalue(node* root)
{
    node* temp=root;
    while(temp->right!=NULL)
    {
        temp=temp->right;
    }
    return temp;
}
node* deletefrombst(node* root,int val)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->data==val)
    {
        //0 child
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }
        //1 child

        //left child
        if(root->left!=NULL && root->right==NULL)
        {
            node* temp=root->left;
            delete root;
            return temp;
        }

        //right child

        if(root->right!=NULL && root->left==NULL)
        {
            node* temp=root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left && root->right)
        {
            int minval=minvalue(root->right)->data;    //bring the minimum value from right subtree
            root->data=minval;     //replace root's data with that minimum value
            root->right=deletefrombst(root->right,minval); //delete the node with the minimum value from the right subtree recursively
            return root; //return the root
        }
        // using left subtree
        /*if(root->left && root->right)
        {

            int maxval=maxvalue(root->left)->data;
            root->data=maxval;
            root->left=deletefrombst(root->left,maxval);
            return root;
        }*/

    }
    else if(root->data>val)
    {
        deletefrombst(root->left,val);
        return root;
    }
    else
    {
        deletefrombst(root->right,val);
        return root;
    }
}


int main()
{
    node* root=NULL;
    input(root);
    //11 8 13 7 9 -1

    levelorder(root);
    cout<<endl;

    cout<<endl;
    buildbst(root,6);
    buildbst(root,10);
    levelorder(root);
    cout<<endl;
    cout<<search(root,6);
    cout<<endl;
    cout<<maxvalue(root)->data<<endl;
    cout<<minvalue(root)->data<<endl;
    cout<<endl;
    root=deletefrombst(root,6);
    cout<<endl;
    levelorder(root);



    return 0;

}
