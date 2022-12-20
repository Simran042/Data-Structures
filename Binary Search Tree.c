#include <stdio.h>
#include <stdlib.h>

//NO DUPLICATES
//n nodes -> (2n)C(n) / n+1 BST
//O(height) = O(log n)

struct node{
    int data;
    struct node* left;
    struct node* right;
}*root = NULL;

struct node* RecSearch(struct node*t, int key)
{
    if(t==NULL)
    {
        return NULL;
    }
    else if(key== t->data)
    {
        return t;
    }
    else if(key< t->data)
    {
        return RecSearch(t->left, key);
    }
    else if(key> t->data)
    {
        return RecSearch(t->right, key);
    }
}

struct node* Search(struct node*t, int key)
{
    if(t==NULL)
    {
        return NULL;
    }
    while(t!=NULL)
    {
        if(key== t->data)
        {
            return t;
        }
        else if(key< t->data)
        {
            t= t->left;
        }
        else
        {
            t= t->right;
        }
    }
    return NULL;
}

struct node* Insert(struct node*t, int key)
{
    struct node*r;
    t=root;
    struct node*newnode;
    if(root == NULL)
    {
        newnode = (struct node*) malloc(sizeof(struct node));
        newnode->data= key;
        newnode->left = newnode->right = NULL;
        root=newnode;
        return root;
    }
    while(t!=NULL)
    {
        r=t;
        if(key== t->data)
        {
            return NULL;
        }
        else if(key< t->data)
        {
            t= t->left;
        }
        else if(key> t->data)
        {
            t= t->right;
        }
    }
    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data= key;
    newnode->right=NULL;
    newnode->left = NULL;
    if(key< r->data){r->left = newnode;}
    else if(key> r->data){r->right = newnode;}
}

struct node* RecInsert(struct node*t, int key)
{
    struct node*r;
    if(t==NULL)
    {
        r= (struct node*) malloc(sizeof(struct node));
        r->data= key;
        r->left= r->right = NULL;
        return r;
    }
    if(key< t-> data)
    {
        t->left = RecInsert(t->left, key);
    }
    else if(key> t->data)
    {
        t->right = RecInsert(t->right, key);
    }
    return t;
}

void Inorder(struct node*p)
{
    if(p)
    {
        Inorder(p->left);
        printf("%d ", p->data);
        Inorder(p->right);
    }
}

struct node* RecDelete(struct node*p , int key)
{
    struct node*q;
    if(p==NULL){return NULL;}

    if(p-> left==NULL && p->right == NULL)
    {
        if(p==root)
        {
            root = NULL;
        }
        free(p);
        return NULL;
    }

    if(key < p->data)
    {
        p->left=RecDelete(p->left, key);
    }
    if(key> p->data)
    {
        p->right= RecDelete(p->right, key);
    }
    else
    {
        if(Height(p->left) > Height(p-> right))
        {
            q= InPre(p-> left);
            p->data = q->data;
            p->left = Delete(p->left, q->data);
        }
        else
        {
            q= InSucc(p-> right);
            p->data = q->data;
            p-> right = Delete(p->right, q-> data);
        }
    }
}


/*struct node* Delete(struct node*p, int key)
{
    p=root;
    struct node*t = Search(root, key);
    if(t->right == NULL && t->left == NULL)
    {

    }
}
*/
int main()
{

    Insert(root, 30);
    Insert(root, 20);
    Insert(root,25);
    RecInsert(root, 56);
    RecInsert(root, 98);
    RecInsert(root, 7);
    Inorder(root);
    printf("\n");

    Inorder(Search(root,0));
    printf("\n");

    Inorder(RecSearch(root,7));
    printf("\n");

    struct node*temp= Search(root, 98);
    if(temp != NULL){printf("Found: %d", temp->data);}
    else{printf("Not found.");}



}
