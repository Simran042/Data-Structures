#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
}* first = NULL;
//struct node*r= NULL;
    //r=(struct node*) malloc(sizeof(struct node));


void create(int A[], int n)
{
    int i;
    struct node*t, *last;
    first = (struct node*) malloc (sizeof(struct node));
    first->data = A[0];
    first->next= NULL;
    last= first;

    for(i=1; i<n; i++)
    {
        t= (struct node*) malloc(sizeof(struct node));
        t -> data= A[i];
        t-> next= NULL;
        last->next =t;
        last = t;
    }
}

void Display(struct node*p)
{
    while(p!= NULL)
    {
        printf(" %d ", p->data);
        p= p->next;
    }
}

void recDisplay(struct node*p)
{
    if(p != NULL)
    {
        printf(" %d ", p->data);
        recDisplay(p->next);
    }
}

void RevRecDisplay(struct node* p)
{
    if(p!= NULL)
    {
        RevRecDisplay(p-> next);
        printf(" %d ", p->data);
    }
}

int CountNodes(struct node*p)
{
    int count=0;
    while(p != NULL)
    {
        count++;
        p= p->next;
    }
    return count;
}

int RecCountNodes(struct node* p)
{
    if(p== NULL)
    {
        return 0;
    }
    else
    {
        return RecCountNodes(p->next) +1 ;
    }
}

int Add(struct node*p)
{
    int sum=0;
    while(p)
    {
        sum= sum+ p->data;
        p= p-> next;
    }
    return sum;
}

int RecAdd(struct node*p)
{
    if(p==NULL)
    {
        return 0;
    }
    else if(p!= NULL)
    {
        return p->data + RecAdd(p->next);
    }
}

int Max(struct node*p)
{
    int max= -3765489;
    while(p != NULL)
    {
        if(p->data > max)
        {
            max= p->data;
        }
        p= p->next;
    }
    return max;
}

int RecMax(struct node*p)
{
    int max= -345667;
    if(p==NULL)
    {
        printf("%d 1\n", max);
        return max;

    }
    else
    {
        if(p->data >= max)
        {
            max= p->data;
            p=p->next;
            RecMax(p);
            printf("%d 2\n", max);
            return max;
        }
        else
        {
            p=p->next;
            RecMax(p);
            printf("%d 3\n", max);
            return max;
        }

    }
}

struct node* search(struct node*p, int key )
{
    while(p!=NULL)
    {
        if(key== p->data)
        {
            return p;
        }
        else
        {
            p= p->next;
        }
    }
    return 0;
}

struct node* RecSearch(struct node*p, int key )
{
    if(p==NULL)
    {
        return NULL;
    }
    else
    {
        if (key==p->data){return p;}
        else{return RecSearch(p->next, key);}
    }
}

struct node* SearchAndFirst(struct node*p, int key )
{
    struct node*q;
    q=first;
    while(p!=NULL)
    {

        if(key== p->data)
        {
            q->next = p->next;
            p->next= first;
            first = p;
            return p;
        }
        else
        {
            q=p;
            p= p->next;
        }
    }
    return 0;
}


struct node* RecSearchAndFirst(struct node*p, int key )
{
    /*
    if(p==NULL)
    {
        return NULL;
    }
    else
    {
        if (key==p->data){return p;}
        else{return RecSearch(p->next, key);}
    }
    */
}

struct node* InsertAtFirst(struct node*p, int n)
{
        struct node*t;
        t= (struct node*) malloc (sizeof(struct node));
        t->data= n;
        t->next= p;
        p = t;
        return p;
}

struct node* InsertAfterIndex(struct node*p, int n, int i)
{
    if(i<0 || i>CountNodes(p)){return NULL;}
    else if(i==0){return InsertAtFirst(p,n);}
    else{
        struct node*t;
        struct node*r;
        r=first;
        t= (struct node*) malloc (sizeof(struct node));
        t->data= n;
        for(int j=0; j<i-1; j++)
        {
            r=r->next;
        }
        t->next = r-> next;
        r->next= t;
        return first;
    }
}

struct node* GetLast(struct node*p)
{
    p=first;
    while(p->next != NULL)
    {
        p=p->next;
    }
    return p;
}

struct node* InsertAtLast(struct node*p, int n)
{
    p=first;
    struct node*t;
    t= (struct node*) malloc(sizeof(struct node));
    t->data = n;
    t->next = NULL;
    struct node*last;
    last = GetLast(p);
    last->next = t;
    last=t;
    return p;
}

struct node* InsertInSorted(struct node*p, int n)
{
    struct node*t;
    t= (struct node*) malloc(sizeof(struct node));
    t->data= n;
    t->next = NULL;
    p=first;
    if(n<= p->data){
        t->next = first;
        first=t;
    }
    else
    {
        while((p->next)->data <= n  && p->next != NULL)
        {
            p= p->next;
        }
        //printf("%d\n", p->data);
        t->next= p->next;
        p->next = t;
        return first;
    }
    //if(p->data <n){return InsertAtLast(first, n);}
}

struct node* DeleteFirst(struct node*p) //Some bug
{
        struct node*q;
        q=first;
        p=q;
        q=q->next;
        //free(p);
        first=q;
        //q->next = NULL;
        return q;
}

struct node* DeleteIdx(struct node*p, int n)
{
        p=first;
        struct node*q,*t;
        t=first;
        q= (struct node*) malloc(sizeof(struct node));
        for(int i=1; i<n; i++)
        {
            q=p;
            p=p->next;
        }
        q->next = p->next;
        p->next= NULL;
        free(p);
        return t;
}

int Sorted(struct node*p)
{
    p= first;
    int c=0;
    int x = -87528;
    while(p!= NULL)
    {
        if(p->data < x){return 0;}
        x=p->data;
        p=p->next;
    }
    return 1;

}

struct node* RemoveDuplicate (struct node*p)
{
    p = first;
    struct node*q;
    while(p->next!=NULL)
    {
        q=p;
        p=p->next;
        if(q->data == p->data)
        {
            q->next= p->next;
            p->next=NULL;
            free(p);
        }
    }
    struct node*r= first;
}

void ReverseLL (struct node*p)
{
    p=first;
    int arr[CountNodes(first)];
    while(p!=NULL)
    {
        for(int i=CountNodes(first)-1; i>=0; i--)
        {
            arr[i]= p->data;
            p=p->next;
        }

    }
    for(int i=0; i<CountNodes(first); i++)
        {
            printf(" %d ",arr[i]);
        }
}

struct node* ReverseLLinLL (struct node*p)
{
    p=first;
    int arr[CountNodes(first)];
    while (p!= NULL)
    {
        for(int i=CountNodes(first)-1; i>=0; i--)
        {
            arr[i]= p->data;
            p=p->next;
        }
    }
    struct node *temp;
    struct node*r = (struct node*) malloc(sizeof(struct node));
    temp=first;
    r=temp;
    //g=first;
    r->next = temp;
    for(int i=0; i<CountNodes(first); i++)
    {
        temp->data= arr[i];
        struct node*a = (struct node*) malloc(sizeof(struct node));
        temp->next=a;
        temp=temp->next;
    }
    temp->next=NULL;
    return r;

}

struct node* ReverseLLwSP(struct node*p)
{
    p= first;
    struct node*s= NULL;
    struct node*q= NULL;
    struct node*r= NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next =r;
    }
    s= q;
    return s;
}


int main()
{
    int A[] = {3,5,7,10,15};
    create(A, 5);
    Display(first);
    printf("\n");
    recDisplay(first);
    printf("\n");
    RevRecDisplay(first);
    printf("\n");
    printf("%d\n",CountNodes(first));
    printf("%d\n",RecCountNodes(first));
    printf("%d\n",Add(first));
    printf("%d\n",RecAdd(first));
    printf("%d\n",Max(first));
    //printf("%d\n",RecMax(first));
    struct node*temp;
    temp= search(first, 7);
    if(temp)
    {
        printf("Key found: %d\n", temp->data);
    }
    else{printf("Sorry vro");}

    temp= RecSearch(first, 7);
    if(temp)
    {
        printf("Key found: %d\n", temp->data);
    }
    else{printf("Sorry vro");}

    temp= SearchAndFirst(first, 7);
    if(temp)
    {
        printf("Key found: %d\n", temp->data);
    }
    else{printf("Sorry vro");}
    Display(first);
    printf("\n");

/*
    temp= RecSearchAndFirst(first, 5);
    if(temp)
    {
        printf("Key found: %d\n", temp->data);
    }
    else{printf("Sorry vro");}
    Display(first);
    printf("\n");
*/

    Display(InsertAtFirst(first, 9));
    printf("\n");
    Display(InsertAfterIndex(first, 6, 4));
    printf("\n");
    //printf("%d\n",(GetLast(first))->data);

    Display(InsertAtLast(first, 3));
    printf("\n");
    int B[] = {3,5,7,10,15};
    create(B, 5);
    Display(first);
    printf("\n");
    InsertInSorted(first, 1);
    InsertInSorted(first, 2);
    InsertInSorted(first, 5);
    //InsertInSorted(first, 28);
    Display(InsertInSorted(first, 2));
    printf("\n");
    Display(DeleteFirst(first));
    printf("\n");
    Display(first);
    printf("\n");
    Display(DeleteIdx(first,4));
    printf("\n");
    if (Sorted(first) ==1) {printf("S");}
    else{printf("NS");}
    printf("\n");
    Display(RemoveDuplicate(first));
    printf("\n");
    ReverseLL(first);
    //ReverseLLinLL(first);
    printf("\n");
    Display(ReverseLLwSP(first));

    return 0;
}

