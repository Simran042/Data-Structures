#include <stdio.h>
#define MaxSize 11

int array[MaxSize];
int top=-1;
int min=0;

void push(int x)
{
    if(top==-1)
    {
        min=x;
        top++;
        array[top]=2*x - min;
    }
    else if(top<MaxSize)
    {
        if(x>=min)
        {
            array[top]= x;
            top= top +1;
        }
        else
        {
            array[top]= 2*x- min;
            top= top +1;
            min=x;
        }
    }
    else
    {
        printf("Overflow");
    }
}

int pop()
{
    int a;
    if(top == -1)
    {
        printf("Empty stack");
        return -11111;
    }
    else
    {
        if(top>=min)
        {
            a= array[top];
            top= top-1;
            return a;
        }
        else
        {
            a= min;
            min= 2*min-a;
            return a;
        }
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

