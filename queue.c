#include <stdio.h>
#define MaxSize 11

int array[MaxSize];
int head=0;
int tail=-1;

void enqueue(int x)
{
    if (tail==-1)
    {
        tail=0;
        array[tail]=x;
        tail++;
    }
    else if(tail< MaxSize)
    {
        array[tail]=x;
        tail++;
    }
    else
    {
        printf("Overflow");
    }
}

int dequeue()
{
    int a;
    if (head==-1)
    {
        printf("Queue empty\n");
        a=-1111;
        head++;
    }
    else if (head==tail)
    {
        a=array[head];
        head=tail=-1;
    }
    else
    {
        a= array[head];
        head++;
    }
    return a;
}

void display(int array[])
{
    for (int i=head; i<tail; i++)
    {
        printf("%d\n", array[i]);
    }
}


int main()
{
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    printf("------\n");
    display(array);
    printf("------\n");
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("------\n");
    display(array);
    printf("------\n");

}
