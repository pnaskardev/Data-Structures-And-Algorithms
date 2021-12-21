#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*first=NULL,*last=NULL;
void create(int n);
void display();
int count_nodes(struct Node *first);
int deletNode(int n);
void insert(int pos,int d);
int main(void)
{
    int n;
    printf("Enter the length of the Linked list you want to make:-");
    scanf("%d",&n);
    int arr[5];
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        create(t);
    }
    display();
    int d,pos;
    printf("Enter the position in which you want to delete:-\n");
    scanf("%d",&pos);
    printf("The deleted element is %d\n",deletNode(pos));
    display();
}
void create(int val)
{
    if(first==NULL)
    {
        first=(struct Node*)malloc(sizeof(struct Node));
         first->data=val;
        first->next=NULL;
        last=first;
        return;
    }
    struct Node *temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=val;
    temp->next=NULL;
    last->next=temp;
    last=temp;
}
void display()
{
    struct Node *h=first;
    if(h==NULL)
    {
        printf("h is null\n");
    }
    else
    {
        while(h!=NULL)
        {
            printf("%d ",h->data);
            h=h->next;
        }
        printf("\n");
    }
}
int count_nodes(struct Node *first)
{
    struct Node *h=first;
    int c=0;
    while(h!=NULL)
    {
        c++;
        h=h->next;
    }
    return c;
}
void insert(int pos,int d)
{
    if(pos<0||pos>count_nodes(first))
    {
        printf("Position is out of bounds\n");
        return;
    }
    else
    {
        struct Node *temp;
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->data=d;
        if(pos==0)
        {
            temp->next=first;
            first=temp;
        }
        else
        {
            struct Node *p=first;
            for(int i=0;i<pos-1;i++)
            {
                p=p->next;
            }
            temp->next=p->next;
            p->next=temp;
        }
    }
}
int deletNode(int n)
{
    struct Node *p=first;
    struct Node *q=NULL;
    int x=-1;
    if(n<1||n>count_nodes(p))
    {
        return x;
    }
    else
    {
        if(n==1)
        {
            q=first;
            x=first->data;
            first=first->next;
            free(q);
            return x;
        }  
        else
        {
            for(int i=1;i<n;i++)
            {
                q=p;
                p=p->next;
            }
            q->next=p->next;
            x=p->data;
            free(p);
            return x;
        } 
    }
    
}