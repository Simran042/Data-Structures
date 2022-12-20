#include <stdio.h>
#include<stdlib.h>

int arr[20];
int size=0;

void Insert (int i)
{
    if (size==0)
    {
        arr[0]=i;
        size++;
    }
    else if(size>0)
    {
        int j=size;
        int temp = i;
        arr[j]=i;
        while(i>arr[j/2] && j!=0 )
        {
            arr[j]= arr[j/2];
            j=j/2;
        }
        arr[j]=i;
        size++;
    }
}

void createHeap(int A[], int n)
{
    for(int i=0; i<n; i++)
    {
        Insert(A[i]);
    }
}

void PrintHeap(int arc[])
{
    for(int i=0; i<size; i++)
    {
        printf("%d ", arc[i]);
    }
}

int Delete()
{
    int k= size-1;
    int t= arr[0];
    arr[0]= arr[k];
    int i=0, j=1;
    while(j<size)
    {
        if(arr[j+1]>arr[j])
        {
            j=j+1;
        }
        if(arr[i] < arr[j])
        {
            int s= arr[j];
            arr[j]=arr[i];
            arr[i]=s;
            i=j;
            j=2*j;
        }
        else{break;}
    }
    return t;
}

int max[20];
void IncOrder()
{
    for(int i=0; i<size; i++)
    {
        max[i]= Delete();
    }
}

int main()
{
    int n=7;
    int A[7]= {1,6,3,5,2,4,8};
    createHeap(A,n);
    //printf("%d\n", size);
    Insert(10);
    Insert(20);
    Insert(40);
    Insert(19);
    Insert(15);
    Insert(1);
    //printf("%d\n", size);
    PrintHeap(arr);
    printf("\n");
    IncOrder();
    PrintHeap(max);
}
