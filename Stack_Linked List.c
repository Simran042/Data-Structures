#include <stdio.h>

struct node{
    int data;
    struct node* next;
} *top= NULL;

void push(int x)
{
    struct node*t;
    t= (struct node*)malloc(sizeof(struct node));
    if(t==NULL)
    {
        printf("Heap full");
    }
    else
    {
        t->data =x;
        t->next= top;
        top= t;
    }
}

int pop()
{
    struct node*t;
    int x=-1;
    if(top==NULL){
        printf("Stack empty");
    }
    else{
        t=top;
        top =top->next;
        x= t->data;
        free(t);
    }
    return x;
}

void Display()
{
    struct node*t;
    t=top;
    if(top==NULL)
    {
        printf("Empty\n");
    }
    else{
            while(t!= NULL)
            {
                printf("%d ", t->data);
                t= t->next;
            }
    }
    printf("\n");
}


int main()
{
    push(10);
    push(20);
    push(40);
    push(60);
    Display();
    pop();
    pop();
    Display();
}
