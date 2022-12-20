#include <stdio.h>
#define MaxSize 11

int array[MaxSize];
int topA=-1;
int topB= -1;


void push_A(int array[], int key)
{
    if(topA==topB-1 || topA==MaxSize-1 || topB==0)
    {
        printf("Overflow");
    }
    else if (topA==-1)
    {
        topA=0;
        array[topA]= key;
    }
    else
    {
        topA= topA+1;
        array[topA]= key;
    }
}

void push_B(int array[], int key)
{
    if(topA==topB-1 || topA==MaxSize-1 || topB==0)
    {
        printf("Overflow");
    }
    else if (topB==-1)
    {
        topB=MaxSize-1;
        array[topB]= key;
    }
    else
    {
        topB= topB-1;
        array[topB]= key;
    }
}

void displayA(int array[])
{
    for(int i=0; i<=topA; i++)
    {
        printf("%d\n", array[i]);
    }
}

void displayB(int array[])
{
    for(int i=MaxSize-1; i>=topB; i--)
    {
        printf("%d\n", array[i]);
    }
}

int pop_A(int array[])
{
    int a;
    a= array[topA];
    topA= topA-1;
    return a;
}

int pop_B()
{
    int a;
    a= array[topB];
    topB= topB+1;
    return a;
}


int main()
{
    push_A(array, 11);
    push_A(array, 10);
    push_A(array, 9);
    push_B(array, 11);
    push_B(array, 10);
    push_B(array, 9);

    displayA(array);
    printf("----------\n");
    displayB(array);
    printf("----------\n");
    int b= pop_A(array);
    displayA(array);
    printf("----------\n");
    b= pop_B(array);
    displayB(array);
}

