/*
Name- Simran Kaur
Entry number- 2021CSB1134
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[32] ;
    int num ;
    printf("Enter number: ");
    scanf("%d", &num);
    int a= num;

    if(num>=0){
        for (int i=0; i<32; i++)
        {
        arr[i]= 0;
        }
        //decimal to binary and storing it in an array
        for (int i=31; i>=0; i--)
        {
            arr[i]= num % 2;
            num= num/2;
        }
        printf("2's complement representation of %d is: ", a);
        //printing the binary rep(2's complement for positive integers)
        for (int i=0; i<32; i++){
            if(i!=0 && i%4==0)
                {
                    printf(" ");
                    printf("%d", arr[i]);
                }
            else{printf("%d", arr[i]);}
        }
    }

    else if(num<0)
    {

        num = 0 - num;
        //decimal to binary of positive num and storing it in array
        for (int i=31; i>=0; i--)
        {
            arr[i]= num % 2;
            num= num/2;
        }
        //taking 1's complement
        for (int i=0; i<32; i++)
        {
            if (arr[i]==0){arr[i]=1;}
            else if(arr[i]==1){arr[i]=0;}
        }
        //adding 1 to it
        int sum(int i){
            if (arr[i]==0){arr[i]=1;}
            else if(arr[i]==1){arr[i]=0; sum(i-1);}
        }
        sum(31);
        //printing 2's complement
        printf("2's complement representation of %d is: ", a);
        for (int i=0; i<32; i++){
            if(i!=0 && i%4==0)
                {
                    printf(" ");
                    printf("%d", arr[i]);
                }
            else{printf("%d", arr[i]);}
        }
    }
    }



