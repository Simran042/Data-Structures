#include <stdio.h>
#define MaxSize 11

int array[MaxSize];
int head=0;
int tail=0;

void circular_enqueue(int x)
{
    if (tail==head-1 ||(head==0&&tail==MaxSize-1))
    {
        printf("Overflow");
    }
    else if(head==-1)
    {
        head=tail=0;
        array[tail]=x;
    }
    else if(tail==MaxSize-1)
    {
        tail=0;
        array[tail]=x;
    }
    else
    {
        tail++;
        array[tail]=x;
    }
}

int circular_dequeue()
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
        array[head]=0;
        head=tail=-1;
    }
    else if (head==MaxSize-1)
    {
        a= array[head];
        array[head]=0;
        head=0;
    }
    else
    {
        a= array[head];
        array[head]=0;
        head++;
    }
    return a;
}

void display(int array[])
{
    if(head<tail)
    {
        for (int i=head; i<=tail; i++)
        {
            printf("%d\n", array[i]);
        }
    }
    if(head>tail)
    {
        for (int i=head; i<MaxSize; i++)
        {
            printf("%d\n", array[i]);
        }
        for (int i=0; i<=tail; i++)
        {
            printf("%d\n", array[i]);
        }
    }
}


int main()
{
    circular_enqueue(3);
    circular_enqueue(4);
    circular_enqueue(5);
    circular_enqueue(6);
    circular_enqueue(7);
    circular_enqueue(8);
    circular_enqueue(9);
    circular_enqueue(10);
    circular_enqueue(11);
    circular_enqueue(12);
    circular_enqueue(13);
    printf("------\n");
    printf("%d\n", head);
    printf("%d\n", tail);
    printf("------\n");
    display(array);
    printf("------\n");
    printf("%d\n", head);
    printf("%d\n", tail);
    printf("------\n");
    printf("%d\n", circular_dequeue());
    printf("%d\n", circular_dequeue());
    printf("%d\n", circular_dequeue());
    printf("%d\n", circular_dequeue());
    printf("------\n");
    printf("%d\n", head);
    printf("%d\n", tail);
    printf("------\n");
    display(array);
    printf("------\n");

}

