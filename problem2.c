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
    int ct;

    if(num == 0)
     {return 1;}
    ct = 0;
    while (a != 0)
    {
        a = a / 10;
        ct++;
    }
    printf("%d\n", ct);

    for(int i=31; i>=0; i--){
        arr[i]= num%10;
        num= num/10;
    }
    for (int i=0; i<32; i++){
            if(i!=0 && i%4==0)
                {
                    printf(" ");
                    printf("%d", arr[i]);
                }
            else{printf("%d", arr[i]);}
        }
    printf("\n");
    if(arr[31-ct+1]==1)
        {
            for(int i=0; i<=31-ct; i++)
                {arr[i]=1;}
        }
    else if(arr[31-ct+1]==0)
        {
            for(int i=0; i<=31-ct; i++)
                {arr[i]=0;}
        }
    for (int i=0; i<32; i++){
            if(i!=0 && i%4==0)
                {
                    printf(" ");
                    printf("%d", arr[i]);
                }
            else{printf("%d", arr[i]);}
        }

    /*if(num>=0){
        for (int i=0; i<32; i++)
        {
        arr[i]= 0;
        }
        for (int i=31; i>=0; i--)
        {
            arr[i]= num % 2;
            num= num/2;
        }
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

    else if(num<0)
    {

        num = 0 - num;

        for (int i=31; i>=0; i--)
        {
            arr[i]= num % 2;
            num= num/2;
        }
        for (int i=0; i<32; i++)
        {
            if (arr[i]==0){arr[i]=1;}
            else if(arr[i]==1){arr[i]=0;}
        }

        int sum(int i){
            if (arr[i]==0){arr[i]=1;}
            else if(arr[i]==1){arr[i]=0; sum(i-1);}
        }
        sum(31);
        printf("2's complement representation of %d is: ", a);
        for (int i=0; i<32; i++){
            if(i!=0 && i%4==0)
                {
                    printf(" ");
                    printf("%d", arr[i]);
                }
            else{printf("%d", arr[i]);}
        }
    }*/
    }



