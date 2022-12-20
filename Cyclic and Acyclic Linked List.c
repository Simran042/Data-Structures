
/*
NAME- SIMRAN KAUR
ENTRY NUMBER- 2021CSB1134
*/



#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node* next;
};


struct node *head=0;
struct node *prev;
struct node *temp;
struct node *start;


//this fxn is allocating memory to new nodes with the input given by main.
struct node* get_node(int i)
{
    /*int x;
    printf("Enter int: ");
    scanf("%d", &x);*/
    struct node * t;
    t= (struct node *) malloc(sizeof(struct node));
    if(t==NULL)
    {
        printf("Memory full.");
        printf("\n");
        return 0;
    }
    else
    {
        t->key=i;
        t->next= NULL;
        return t;
    }

}

/*This fxn is inserting the node attained from getnode to the linked list(basically this fxn is linking the list) */
void insert(struct node*t)
{
    if(head==0){head= temp= t;}
    else{
        temp->next=t;
        temp= t;
    }

}

/*this is an optional fxn to display the nodes of linked list. you can uncomment the display() called in main fxn to see the nodes of linked list in order*/
void display()
{
    struct node*buff;
    buff= head;

    while(buff != NULL)
    {
        printf("%d\n",buff-> key);
        buff = buff->next;
    }
}

/*This fxn is using Floyd's algorithm to detect the presence of a cycle in linked list*/
int DetectCycle()
{
    struct node *slowptr= head;
    struct node *fastptr= head;
    while(fastptr != NULL && fastptr->next !=NULL){
        slowptr= slowptr->next;
        fastptr= fastptr->next->next;
        if(fastptr==slowptr){return 1;}
        }
}

/*This fxn is used to find the length and distance from head of the starting node of the cycle(if present)*/
void DetectFindStart()
{
    struct node *slowptr= head;
    struct node *fastptr= head;
    int count=0;
    int i=0;
    int j=0;

    struct node *fun;
    if(fastptr != NULL && fastptr->next !=NULL){
            count++;
            slowptr= slowptr->next;
            fastptr= fastptr->next->next;
    }
    while(fastptr != NULL && fastptr->next !=NULL &&slowptr != fastptr)
        {
            count++;
            fun= slowptr;
            slowptr= slowptr->next;
            fastptr= fastptr->next->next;
        }
    //printf("%d\n", slowptr->key);
    //printf("%d\n", fastptr->key);

    fastptr= head;
    while(fastptr!= slowptr)
    {
        fastptr = fastptr->next;
        slowptr= slowptr->next;
    }
    //printf("%d\n", slowptr->key);
    //printf("%d\n", fastptr->key);
    struct node *ref= head;
    while(ref!= slowptr){
        i++;
        ref=ref->next;
    }

    struct node* abc = slowptr->next;
    while(abc != slowptr)
    {
        j++;
        abc= abc->next;
    }
    printf("The linked list has a cycle of length %d and the distance of the start node of the cycle from the head of the linked list is %d.", j+1, i);
    printf("\n");
    printf("\n");



}

int main(){
    /*Taking user input for linked list with or without cycle*/
    char ch;
    printf("Press Y for linked list with a cycle and N for without cycles: ");
    scanf("%c", &ch);
    printf("\n");
    if(ch=='N')
    {
        int n;
        printf("Enter the size (number of edges) of linked list without cycle: ");
        scanf("%d", &n);
        printf("\n");
        //assigninig value i to 'i'th node
        for(int i=0; i<n; i++)
        {
                struct node*t =get_node(i+1);
                insert(t);
        }
        //display();
        //taking output from detect cycle fxn and printing result accordingly
        int y= DetectCycle();
        if(y==1)
            {
                printf("There exists a cycle.");
                printf("\n");
            }
        else
            {
                printf("The linked list contains no cycle.");
                printf("\n");
            }
    }

    if(ch=='Y')
    {
        //taking inputs of length and starting node from user
        int l;
        printf("Enter the length of cycle in the linked list: ");
        scanf("%d", &l);
        printf("\n");
        int w;
        printf("Enter the size (number of edges) of linked list without cycle: ");
        scanf("%d", &w);
        printf("\n");
        //taking boundary case when length of cycle=0
        if(l==0){
            printf("The linked list contains no cycle.");
            printf("\n");
        }
        else{
        //display();
        // getting n number of nodes where n= length of loop + length of straight list
        for(int i=0; i<l+w; i++)
        {
                struct node*t =get_node(i);
                insert(t);
        }
        //printf("%d", (*temp).key);
        //getting start ptr at the starting point of loop
        for(int i=0; i<l+w; i++)
        {
                start= head;
                for(int j=0; j<w; j++){
                    start=start->next;
                }
        }
        //printf("%d", (*start).key);
        temp->next= start;
        //display();
        //uncomment the below code to get DetectCycle fxn for this case
        /*int y= DetectCycle();
        if(y==1)
            {
                printf("There exists a cycle.");
            }
        else
            {
                printf("The linked list contains no cycle.");
            }*/

        DetectFindStart();
        }
    }



}

