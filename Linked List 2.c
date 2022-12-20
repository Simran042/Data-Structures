#include <stdio.h>

struct node
{
    int key;
    struct node* next;
};


struct node* get_node (int x)
{
    struct node* t;
    t= (struct node*)malloc(sizeof(struct node));
    if(t==NULL)
    {
        printf("Memory full");
    }
    else
    {
        t->key= x;
        t->next = NULL;
    }
    return t;
}

struct node* insert_at_first (struct node*first,struct node*last,struct node*t)
{
    struct node*temp;
    temp= (struct node*)malloc(sizeof(struct node));
    temp= first;
    first=t;
    t->next = temp;
    return first;
}

void display(struct node*first)
{
    struct node*buff;
    buff= (struct node*)malloc(sizeof(struct node));
    buff= first;

    while(buff->next != NULL)
    {
        printf("%d\n",buff-> key);
        buff = buff->next;
    }

}

int main()
{
    struct node*first;
    struct node*last;
    struct node*t;

    first= (struct node*)malloc(sizeof(struct node));
    last= (struct node*)malloc(sizeof(struct node));
    t= (struct node*)malloc(sizeof(struct node));

    t=get_node(19);
    first= insert_at_first(first, last, t);
    display(first);
}
