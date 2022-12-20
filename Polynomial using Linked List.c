#include <stdio.h>
#define Maxp 100

struct node{
    int coeff[Maxp +1];
    int highp
};

typedef struct node* poly;

void zeropoly(poly p1)
{
    for (int i=0; i<= Maxp; i++)
    {
        p1->coeff[i] = 0;
        p1->highp = 0;
    }
}

int Max(int a, int b)
{
    if(a>=b){return a;}
    else{return b;}
}

void print(poly p){
    for(int i=0; i< p->highp; i++)
    {
        printf("%d, %d\n", i, p->coeff[i]);
    }
}

void add(const poly p1, const poly p2)
{
    poly sum;
    zeropoly(sum);
    sum-> highp= Max(p1->highp, p2->highp);
    for(int i=sum->highp; i>=0; i--)
    {
        sum->coeff[i]= p1->coeff[i]+ p2->coeff[i];
    }
    print(sum);
}

void multiply(const poly p1, const poly p2)
{
    poly prod;
    zeropoly(prod);
    prod-> highp= p1-> highp + p2-> highp;
    if(prod->highp > Maxp)
    {
        printf("No space");
    }
    else{
        for(int i=0; i<p1->highp; i++)
        {
            for(int j=0; j< p2->highp; j++)
            {
                prod-> coeff[i+j]= (p1->coeff[i])*(p2-> coeff[j]);
            }
        }
    }
    print(prod);
}

int main()
{
    poly p1, p2;
    zeropoly(p1);
    zeropoly(p2);
    p1->coeff[1]=18;
    p1->coeff[3]=2;
    p1->coeff[6]=5;
    p2->coeff[3]=18;
    p2->coeff[7]=23;
    add(p1, p2);
    multiply(p1, p2);
    return 0;
}



