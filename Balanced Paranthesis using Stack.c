#include <stdio.h>

struct stack{
    int size;
    int top;
    char*s;
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

int isBalance(char*exp)
{
    struct stack st;
    st.size= strlen(exp);
    st.top=-1;
    st.s= (char*)malloc((st.size) * sizeof(char));
    for(int i=0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){push(&st, exp[i]);}
        else if(exp[i]==')'){
                if(isEmpty(&st)){return 0;}
                else{pop(&st);}
        }
    }
    if(isEmpty(&st)){return 1;}
    return 0;
}

int main()
{
    char * exp = "(a+b)*()(c-d)";
    printf("%d ", isBalance(exp));
}
