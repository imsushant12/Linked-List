//by Sushant Gaurav

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *next;
};
struct node *last=NULL;

void viewList()
{
    if(last==NULL)
        printf("\nList is empty\n");
    else
    {
        struct node *temp;
        temp=last->next;
        do
        {
            printf("%d ",temp->info);
            temp->next;
        }while(temp!=last->next);
    }
}

void addatbeg()
{
    int data;
    struct node *temp;
    printf("\nEnter data to be entered\n");
    scanf("%d",&data);
    temp->info=data;
    temp->next=last->next;
    last->next=temp;
}

void addatlast()
{
    int data;
    struct node *temp;
    temp=malloc(sizeof(struct node));
    printf("\nEnter data to be entered\n");
    scanf("%d",&data);
    temp->info=data;
    temp->next=last->next;
    last->next=temp;
    last=temp;
}

void insertafter()
{
    int data,value;
    struct node *temp,*n;
    printf("\nEnter number after which you want to enter number\n");
    scanf("%d ",&value);
    temp=last->next;
    do
    {
        if(temp->info==value)
        {
            n=malloc(sizeof(struct node));
            printf("\nEnter data to be entered\n");
            scanf("%d ",&data);
            n->info=data;
            n->next=temp->next;
            temp->next=n;
            if(temp==last)
                last=n;
            break;
        }
        temp=temp->next;
        }while(temp!=last->next);
    printf("\n%d is not in the list\n");
}

void del()
{
    int value;
    struct node *temp,*trav;
    printf("\nEnter value to be deleted\n");
    scanf("%d",&value);
    if(last==NULL)
        printf("\nList is empty\n");
    if(last==last->next)
    {
        if(last->info==value)
        {
            temp=last;
            last=NULL;
            free(temp);
        }
    }
    if(last->next->info==value)
    {
        temp=last->next;
        last->next=temp->next;
        free(temp);
    }
    temp=last->next;
    while(temp->next!=last)
    {
        if(temp->next->info==value)
        {
            trav=temp->next;
            temp->next=trav->next;
            free(trav);
        }

        if(last->info==value)
        {
            trav=last;
            temp->next=last->next;
            last=temp;
            free(trav);
        }
    }
    printf("\n Not found %d ",value);
}

void create()
{
    int n,i,data;
    printf("\nEnter number of elements to be entered\n");
    scanf("%d",&n);
    addatbeg();
    for(i=2;i<=n;i++)
    {
        addatlast();
    }
}


main()
{
    int choice;
    while(1)
    {
        printf("\nEnter your choice : \n");
        printf("\t1 To view list\n");
        printf("\t2 For insertion at starting\n");
        printf("\t3 For insertion at end\n");
        printf("\t4 For insertion at any position\n");
        printf("\t5 For deletion of an element\n");
        printf("\t6 For creation of list\n");
        printf("\t7 To exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
                viewList();
                break;
        case 2:
                addatbeg();
                break;
        case 3:
                addatlast();
                break;
        case 4:
                insertafter();
                break;
        case 5:
               del();
               break;
        case 6:
                create();
                break;
        case 7:
                exit(1);
                break;
        default:
            printf("Incorrect Choice\n");
        }
    }
}

/*

To convert circular linked list in singly linked list:
temp=last;
last=last->link;
start=last;
temp->link=NULL;

*/
