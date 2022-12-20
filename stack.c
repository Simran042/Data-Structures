#include <stdio.h>
#define MaxSize 6

int array[MaxSize];
int top=0;


void push(int x)
{
    if (top< MaxSize)
    {
        array[top]= x;
        top=top+1;
    }
    else
    {
        printf("Overflow");
    }
}

int pop()
{
    if (top>0)
    {
        top = top-1;
        return array[top];
    }
    else
    {
        printf("Empty stack");
        return -1;
    }
}
void display(int array[])
{
    for(int i=0; i<top; i++)
    {
        printf("%d\n", array[i]);
    }
}

int main()
{
    push(3);
    push(4);
    push(7);
    push(9);
    push(11);
    push(13);
    display(array);
    printf("------\n");
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("------\n");
    display(array);
}
