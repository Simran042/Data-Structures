#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int* s;
};

void create(struct stack* st)
{
    printf("give size: ");
    scanf("%d", &st->size);
    st->top =-1;
    st->s = (int*)malloc(st->size * sizeof(int));
}

void Display(struct stack* st)
{
    for(int i=st->top; i>=0; i--)
    {
        printf("%d ",st->s[i]);
    }
}

void push(struct stack* st, int x)
{
    if(st->top == st->size-1)
    {
        printf("Overflow\n");
    }
    else{
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct stack*st)
{
    int x= -1;
    if(st->top == -1)
    {
        printf("Underflow");
    }
    else{
        x= st->s[st->top];
        st->top --;
    }
    return x;
}

/*int peek(struct stack*st, int pos)
{
    int x=-1;
    struct stack*st2= (struct stack*)malloc(sizeof(struct stack));
    st2=st;
    for(int i=0; i<pos; i++)
    {
        x= st2->s[st2->top];
        st2->top --;
    }
    return x;
}*/

int peek2(struct stack*st, int pos)
{
    int x = -1;
    if(st->top - pos +1 <0){printf("Invalid position");}
    else
    {
        x= st->s[st->top - pos +1];
    }
    return x;
}

int isEmpty(struct stack* st)
{
    if(st->top == -1)
    {
        return 1;
    }
    else{return 0;}
}

int isFull(struct stack*st)
{
    if(st->top== st->size -1){return 1;}
    else{return 0;}
}

int stackTop (struct stack* st)
{
    if(st->top == -1)
    {
        return -1;
    }
    else
    {
        return st->s[st->top];
    }
}

int main()
{
    struct stack*st= (struct stack*)malloc(sizeof(struct stack));
    create(st);
    push(st, 10);
    push(st, 20);
    push(st, 30);
    push(st, 700);
    //Display(st);
    //printf("%d\n", peek(st,2));
    //Display(st);
    printf("%d\n", peek2(st,1));
    Display(st);
}
