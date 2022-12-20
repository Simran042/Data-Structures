#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node*left;
    int data;
    struct node*right;
    int height;
};

struct node*root = NULL;

int NodeHeight(struct node*p)
{
    int hl, hr;
    if(p!=NULL && p->left !=NULL)
    {
        hl = p->left->height;
    }
    else{
        hl=0;
    }
    if(p!=NULL && p->right !=NULL)
    {
        hr = p->right->height;
    }
    else{
        hr=0;
    }

    if(hl>hr){return hl+1;}
    else if(hl<hr){return hr+1;}

}

struct node*LLRotation(struct node*p)
{
    struct node*pl = p->left;
    struct node* plr= pl->right;
    pl->right= p;
    p->left = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root==p)
    {
        root=pl;
    }

    return pl;
}

struct node*LRRotation(struct node*p)
{
    struct node* pl = p->left;
    struct node* plr= pl -> right;
    struct node* plrr= plr-> right;
    struct node* plrl= plr->left;
    pl->right= plrl;
    p->left = plrr;
    plr->right = p;
    plr->left=pl;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if(root==p)
    {
        root=plr;
    }

    return plr;

}

struct node*RLRotation(struct node*p)
{
    struct node* pr = p-> right;
    struct node* prl = pr-> left;
    struct node* prlr = prl-> right;
    struct node* prll = prl-> left;

    prl->right = pr;
    prl->left = p;
    p-> right = prll;
    pr-> left = prlr;

    if(root ==p)
    {
        root = prl;
    }

    return prl;
}

struct node*RRRotation(struct node*p)
{
    struct node*pr= p->right;
    struct node*prl= pr->left;
    pr->left= p;
    p->right = prl;
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    if(root==p)
    {
        root=pr;
    }

    return pr;
}

struct node* Insert(struct node*p, int k)
{
    struct node*t =NULL;
    if(p==NULL)
    {
        t= (struct node*) malloc(sizeof(struct node));
        t->data = k;
        t->left = NULL;
        t->right= NULL;
        t->height=1;
        return t;
    }
    else{
        if(k<p->data)
        {
            p->left = Insert(p->left, k);
        }
        else if(k> p->data)
        {
            p->right = Insert(p->right, k);
        }
        else if(k== p->data)
        {
            printf("Cant insert duplicates ;-;");
            return NULL;
        }
        p->height = NodeHeight(p);
        if(BalanceFactor(p)==2 && BalanceFactor(p->left)==1)
        {
            return LLRotation(p);
        }
        else if(BalanceFactor(p)==2 && BalanceFactor(p->left)==-1)
        {
            return LRRotation(p);
        }
        else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==-1)
        {
            return RRRotation(p);
        }
        else if(BalanceFactor(p)==-2 && BalanceFactor(p->right)==1)
        {
            return RLRotation(p);
        }

        return p;
    }
}

int BalanceFactor(struct node*p)
{
    int hl, hr;
    if(p!=NULL && p->left !=NULL)
    {
        hl = p->left->height;
    }
    else{
        hl=0;
    }
    if(p!=NULL && p->right !=NULL)
    {
        hr = p->right->height;
    }
    else{
        hr=0;
    }

    return hl-hr;
}

void inOrder(struct node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        inOrder(root->left);
        inOrder(root->right);
    }
}


struct node* Search(struct node*p, int k)
{
    if(p==NULL)
    {
        return NULL;
    }
    else if(k<p->data)
    {
        p= Search(p->left, k);
    }
    else if(k==p->data)
    {
        return p;
    }
    else if(k>p->data)
    {
        p= Search(p->right, k);
    }
    return p;
}

int main()
{
    root = Insert(root, 0);
    /*Insert(root, 1);
    Insert(root, 2);
    Insert(root, 3);
    Insert(root, 4);*/
    for(int i=1; i<=24;i++)
    {
        Insert(root, i);
    }
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    struct node*l= Search(root, 15);
    printf("%d\n", l->height);
    printf("%d\n", BalanceFactor(l));
}
