#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int info;
    struct node *left;
    struct node *right;
}*root;

class BinarySearchTree
{
public :
    void find(int,node **,node**);
    void insertValue(node *,node*);
    void deleteValue(int);
    void caseA(node *,node *);
    void caseB(node *,node *);
    void caseC(node *,node *);
    void preorder(node *);
    void inorder(node *);
    void postorder(node *);
    void display(node *,int);
    BinarySearchTree()
    {
        root=NULL;
    }
};

int main()
{
    int choice,num;
    BinarySearchTree bst;
    node *temp;
    while(1)
    {
        cout<<"Operations on Binary Search Tree"<<endl;
        cout<<"1.Insert Element"<<endl;
        cout<<"2.Delete Element"<<endl;
        cout<<"3.Inorder Traversal"<<endl;
        cout<<"4.Preorder Traversal"<<endl;
        cout<<"5.Postorder Traversal"<<endl;
        cout<<"6.Display"<<endl;
        cout<<"7.Quit"<<endl;
        cout<<"Enter your Choice :";
        cin>>choice;
        switch(choice)
        {
        case 1:
            temp=new node;
            cout<<"Enter the Number to be Inserted :";
            cin>>temp->info;
            bst.insertValue(root,temp);
            break;
        case 2:
            if(root==NULL)
            {
                cout<<"Tree is Empty,Nothing to be Deleted"<<endl;
                continue;
            }
            cout<<"Enter the Number to be Deleted :";
            cin>>num;
            bst.deleteValue(num);
            break;
        case 3:
            cout<<"Inorder Traversal of Binary Search Tree :"<<endl;
            bst.inorder(root);
            cout<<endl;
            break;
        case 4:
            cout<<"Preorder Traversal of Binary Search Tree :"<<endl;
            bst.preorder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"Postorder Traversal of Binary Search Tree :"<<endl;
            bst.postorder(root);
            cout<<endl;
            break;
        case 6:
            cout<<"Display Binary Search Tree :"<<endl;
            bst.display(root,1);
            cout<<endl;
            break;
        case 7:
            exit(1);
        default :
            cout<<"Wrong Choice!"<<endl;

        }
    }
    return 0;
}

void BinarySearchTree::find(int item,node **par,node **loc)
{
    node *ptr,*ptrSave;
    if(root==NULL)
    {
        *loc=NULL;
        *par=NULL;
        return;
    }
    if(item==root->info)
    {
        *loc=root;
        *par=NULL;
        return;
    }
    if(item<root->info)
    {
        ptr=root->left;
    }
    else
    {
        ptr=root->right;
    }
    ptrSave=root;
    while(ptr !=NULL)
    {
        if(item==ptr->info)
        {
            *loc=ptr;
            *par=ptrSave;
            return;
        }
        ptrSave=ptr;
        if(item<ptr->info)
        {
            ptr=ptr->left;
        }
        else
        {
            ptr=ptr->right;
        }
    }
    *loc=NULL;
    *par=ptrSave;
}

void BinarySearchTree::insertValue(node *tree,node *newNode)
{
    if(root==NULL)
    {
        root=new node;
        root->info=newNode->info;
        root->left=NULL;
        root->right=NULL;
        cout<<"Root Node is Added"<<endl;
        return;
    }
    if(tree->info==newNode->info)
    {
        cout<<"Element is Already in the Tree"<<endl;
        return;
    }
    if(tree->info>newNode->info)
    {
        if(tree->left!=NULL)
        {
            insertValue(tree->left,newNode);
        }
        else
        {
            tree->left=newNode;
            (tree->left)->left=NULL;
            (tree->left)->right=NULL;
            cout<<"Node Added to Left"<<endl;
            return;
        }
    }
    else
    {
        if(tree->right!=NULL)
        {
            insertValue(tree->right,newNode);
        }
        else
        {
            tree->right=newNode;
            (tree->right)->left=NULL;
            (tree->right)->right=NULL;
        }
    }
}

void BinarySearchTree::deleteValue(int item)
{
    node *parent,*location;
    if(root==NULL)
    {
        cout<<"Tree is Empty"<<endl;
        return;
    }
    find(item,&parent,&location);
    if(location==NULL)
    {
        cout<<"Item is not Present in Tree"<<endl;
        return;
    }
    if(location->left==NULL && location->right==NULL)
    {
        caseA(parent,location);
    }
    if(location->left!=NULL && location->right==NULL)
    {
        caseB(parent,location);
    }
    if(location->left==NULL && location->right!=NULL)
    {
        caseB(parent,location);
    }
    if(location->left!=NULL && location->right!=NULL)
    {
        caseC(parent,location);
    }
    free(location);
}

void BinarySearchTree::caseA(node *par,node *loc)
{
    if(par==NULL)
    {
        root=NULL;
    }
    else
    {
        if(loc==par->left)
        {
            par->left=NULL;
        }
        else
        {
            par->right=NULL;
        }
    }
}

void BinarySearchTree::caseB(node *par,node *loc)
{
    node *child;
    if(loc->left!=NULL)
    {
        child=loc->left;
    }
    else
    {
        child=loc->right;
    }
    if(par==NULL)
    {
        root=child;
    }
    else
    {
        if(loc==par->left)
        {
            par->left=child;
        }
        else
        {
            par->right=child;
        }
    }
}

void BinarySearchTree::caseC(node *par,node *loc)
{
    node *ptr,*ptrSave,*struc,*parStruc;
    ptrSave=loc;
    ptr=loc->right;
    while(ptr->left!=NULL)
    {
        ptrSave=ptr;
        ptr=ptr->left;
    }
    struc=ptr;
    parStruc=ptrSave;
    if(struc->left==NULL && struc->right==NULL)
    {
        caseA(parStruc,struc);
    }
    else
    {
        caseB(parStruc,struc);
    }
    if(par==NULL)
    {
        root=struc;
    }
    else
    {
        if(loc==par->left)
        {
            par->left=struc;
        }
        else
        {
            par->right=struc;
        }
    }
    struc->left=loc->left;
    struc->right=loc->right;
}

void BinarySearchTree::preorder(node *ptr)
{
    if(root==NULL)
    {
        cout<<"Binary Search Tree is Empty"<<endl;
        return;
    }
    if(ptr!=NULL)
    {
        cout<<ptr->info<<" ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void BinarySearchTree::inorder(node *ptr)
{
    if(root==NULL)
    {
        cout<<"Binary Search Tree is Empty"<<endl;
        return;
    }
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        cout<<ptr->info<<" ";
        inorder(ptr->right);
    }
}

void BinarySearchTree::postorder(node *ptr)
{
    if(root==NULL)
    {
        cout<<"Binary Search Tree is Empty"<<endl;
        return;
    }
    if(ptr!=NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->info<<" ";
    }
}

void BinarySearchTree::display(node *ptr,int level)
{
    int i;
    if(ptr!=NULL)
    {
        display(ptr->right,level+1);
        cout<<endl;
        if(ptr==root)
        {
            cout<<"Root->: ";
        }
        else
        {
            for (i=0;i<level;i++)
            {
                cout<<"     ";
            }
        }
        cout<<ptr->info;
        display(ptr->left,level+1);
    }
}
