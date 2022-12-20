#include <stdio.h>

struct stack{
    char*s;
    int top;
    int size;
};

void push(struct stack* st, char x)
{
    if(st->top == st->size-1)
    {
        printf("Overflow\n");
    }
    else{
        st->top++;
        st->s[st->top] = x;
    }
}

char pop(struct stack*st)
{
    int x= -1;
    if(st->top == -1)
    {
        printf("Underflow");
    }
    else{
        x= st->s[st->top];
        st->top --;
    }
    return x;
}

void Display(struct stack* st)
{
    for(int i=st->top; i>=0; i--)
    {
        printf("%c ",st->s[i]);
    }
}

int isEmpty(struct stack* st)
{
    if(st->top == -1)
    {
        return 1;
    }
    else{return 0;}
}

int isOperand(char x)
{
    if (x=='+' || x=='-'||x=='*'|| x=='/')
    {
        return 0;
    }
    return 1;
}

int prec(char x)
{
    if(x=='+'|| x=='-')
    {
        return 1;
    }
    if(x=='*'|| x=='/')
    {
        return 2;
    }
    else
    {
        return 0;
    }

}

char* convert(char*infix)
{
    struct stack st;
    st.top=-1;
    st.size= strlen(infix)+1;
    st.s = (char*)malloc(st.size*sizeof(char));
    char*postfix = (char*)malloc((strlen(infix)+1)*sizeof(char));
    int i=0, j=0;
    while(infix[i] != '\0')
    {
        if(isOperand(infix[i])){postfix[j++]= infix[i++];}
        else
        {
            if(prec(infix[i])> prec(st.s[st.top])){push(&st, infix[i++]);}
            else{postfix[j++]= pop(&st);}
        }
    }
    while(isEmpty(&st)==0)
    {
        postfix[j++]= pop(&st);
    }
    postfix[j]=0;
    return postfix;
}

int eval(char*postfix)
{
    struct stack st;
    st.top=-1;
    st.size= strlen(postfix)+1;
    st.s = (char*)malloc(st.size*sizeof(char));
    int x1, x2, r;
    for(int i=0; postfix[i]!='\0'; i++)
    {
        if(isOperand(postfix[i]))
        {
            push(&st, postfix[i]-'0');
        }
        else
        {
            x2 = pop(&st);
            x1 = pop(&st);
            switch(postfix[i])
            {
            case '+':
                {
                    r= x1+x2;
                    push(&st, r);
                    break;
                }
            case '-':
                {
                    r= x1-x2;
                    push(&st, r);
                    break;
                }
            case '*':
                {
                    r= x1*x2;
                    push(&st, r);
                    break;
                }
            case '/':
                {
                    r= x1/x2;
                    push(&st, r);
                    break;
                }
            }
        }
    }
    return pop(&st);
}

int main()
{
    char*infix = "8+4/2-6";
    char*postfix= convert(infix);
    printf("%s ", postfix);
    printf("\n");
    printf("%d ",eval(postfix));
}
