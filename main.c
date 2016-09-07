#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#define NULL 0
struct linked_list
{
    int value;
    struct linked_list *next;

};
typedef struct linked_list node;
node *temp;

int main()
{
    node *head;
    int opt;
    int pos,place;
    char rpt;
    void create(node *p);
    void createnew(node *p);
    //void createnewhead(node *p);
    int count(node *p);
    void print(node *p);
    void insertbeg(node *p);
    void insertmid(node *p,int place);
    void insertend(node *p);
    node *insert(node *p,int a);
    head=(node *)malloc(sizeof(node));
    create(head);
    count(head);
    printf("\n");
    print(head);
    printf("\n number of elements=%d \n ",count(head));
    printf("do you want to insert a node in linked list \n 1 for yes and any for no \n");
    scanf("\n %d",&opt);
    if(opt==1)
    {
        printf("choose the position where you want to insert \n");
        printf(" 1. beggining \n 2. middle \n 3. end \n");
        scanf("\n %d",&pos);
        switch(pos)
        {
        case 1:
            insertbeg(head);
            //createnew(head);
            //print(head);
            //createnewhead();
            break;
        case 2:
            printf("enter the value after which you want to insert the new node");
            scanf("%d",&place);
            insertmid(head,place);
            print(head);
            break;
        case 3:
            insertend(head);
            printf("\n");
            print(head);
            break;
        default:
            printf("wrong choice");
            break;
        }
    }
    return 0;
}
void create(node *list)
{
        //int num;
        /*int n;
        printf("enter the number \n");
        scanf("%d",&num);
        if(num!=-999)
        {

            list->value=num;
            printf("wanna node \t 0 for yes\n");
            scanf("%d",&n);
            if(n==0)
            {
                list->next=malloc(sizeof(node));
                create(list->next);
            }
            else
            {
                list->next=NULL;
            }

        }
        else
        {
            //list->value=NULL;
            list->next=NULL;

        }*/

        printf("input a number \n");
        scanf("%d",&list->value);
        if(list->value==-999)
        {
            list->next = NULL;
        }
        else
        {
            list->next = (node *)malloc(sizeof(node));
            create(list->next);
        }
}
void print(node *list)
{
    if(list->next!=NULL)
    {
        printf("%d\n",list->value);
        //if(list->next->next==NULL)
        //    printf("%d",list->next->value);
        print(list->next);
    }
}
int count(node *list)
{
    if(list->next==NULL)
        return (0);
    else
        return (1+count(list->next));

}
void insertbeg(node *head)
{
    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    printf("enter the number \n");
    scanf("%d",&newnode->value);
    newnode->next=head;
    head=newnode;
    printf("\n");
    print(head);
}
void insertend(node *list)
{
    if(list->next->next==NULL)
    {
        node *newnode;
        newnode=(node *)malloc(sizeof(node));
        printf("enter the new number\n");
        scanf("%d",&newnode->value);
        printf("\n");
        newnode->next=list->next;
        list->next=newnode;

    }

    else
    {
        insertend(list->next);
    }

}
void insertmid(node *list,int place)
{

    if(list->value==place)
    {
        node *newnode;
        newnode=(node *)malloc(sizeof(node));
        printf("enter the value you want to insert");
        scanf("%d",&newnode->value);
        newnode->next=list->next;
        list->next=newnode;
    }
    else
    {
        insertmid(list->next,place);
    }
}
