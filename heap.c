#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int arr[];
void InsertMaxHeap(int A[], int n)
{
    int temp, i=n;
    temp= A[i];
    while(i>1 && temp > A[i/2])
    {
        A[i]= A[i/2];
        i=i/2;
    }
    A[i]=temp;
}

void InsertMinHeap(int A[], int n)
{
    int temp, i=n;
    temp= A[i];
    while(i>1 && temp < A[i/2])
    {
        A[i]= A[i/2];
        i=i/2;
    }
    A[i]=temp;
}

void CreateMaxHeap()
{
    int A[]= {0,10,34,7,58,92,3};
    for(int i=2; i<=6; i++)
    {
        InsertMaxHeap(A, i);
    }
    for(int i=0; i<=6; i++)
    {
        printf("%d ", A[i]);
    }
}

void CreateMinHeap()
{
    int A[]= {0,10,34,7,58,92,3};
    for(int i=2; i<=6; i++)
    {
        InsertMinHeap(A, i);
    }
    for(int i=0; i<=6; i++)
    {
        printf("%d ", A[i]);
    }
}

void DeleteMax(int A[], int n)
{
    int x,i,j;
    x= A[n];
    A[1]= A[n];
    i=1;
    j=2*i;
    while(j<n-1)
    {
        if(A[j+1] > A[j])
        {
            j=j+1;
        }
        if (A[i]<A[j])
        {
            int d=A[i];
            A[i]=A[j];
            A[j]=d;
            i=j;
            j=2*j;
        }
    }

}

int main()
{
    CreateMaxHeap();
    printf("\n");
    CreateMinHeap();

}
