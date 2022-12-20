/*
Name- Simran Kaur
Entry number- 2021CSB1134
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[32] ;
    int num,count ;
    printf("Input: ");
    scanf("%d", &num);
    int a= num;
    count=0;
    //for positive integers
    if(num>=0){
        for (int i=0; i<32; i++)
        {
        arr[i]= 0;
        }
        //converting decimal to binary and storing in array
        for (int i=31; i>=0; i--)
        {
            arr[i]= num % 2;
            num= num/2;
        }
        printf("Output: ", a);
        //counting number of 1's and storing it in variable count
        for (int i=0; i<32; i++){
            if(arr[i]==1){count++;}
            else if(arr[i]==0){continue;}
        }
        printf("%d", count);
    }

    else if(num<0)
    {

        num = 0 - num;
        //converting positive of num to binary
        for (int i=31; i>=0; i--)
        {
            arr[i]= num % 2;
            num= num/2;
        }
        //taking 1s complement
        for (int i=0; i<32; i++)
        {
            if (arr[i]==0){arr[i]=1;}
            else if(arr[i]==1){arr[i]=0;}
        }
        //adding 1 to complement
        int sum(int i){
            if (arr[i]==0){arr[i]=1;}
            else if(arr[i]==1){arr[i]=0; sum(i-1);}
        }
        sum(31);
        printf("Output: ", a);
        //counting number of 1's
        for (int i=0; i<32; i++){
            if(arr[i]==1){count++;}
            else if(arr[i]==0){continue;}
        }
        printf("%d", count);
    }
    }




