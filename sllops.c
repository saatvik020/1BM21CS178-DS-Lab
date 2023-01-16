#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* create();
struct node* concat(struct node* , struct node*);
struct node* reverse(struct node*);
struct node* sort(struct node*);
void display(struct node*);

int main()
{
    int ch;
    struct node *head = NULL;
    struct node *head1 = create();
    struct node *head2 = create();
    do
    {
        printf("\n1. Concatenate\n2. Reverse\n3. Sort\n4. Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head = concat(head1,head2);
                    display(head);
                    break;
            case 2: head = reverse(head2);
                    display(head);
                    break;
            case 3: head = sort(head2);
                    display(head);
                    break;
            case 4: exit(0);
            default: printf("\nInvalid Input");
        }
    }while(1);
}

struct node* create()
{
    int s , i=0;
    printf("\nEnter the size of List: ");
    scanf("%d",&s);
    struct node *head = NULL;
    while(i<s)
    {
        struct node *new = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data: ");
        scanf("%d",&new->data);
        if(head == NULL)
        {
            new->next = NULL;
            head = new;
        }
        else
        {
            struct node *temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            new->next = NULL;
            temp->next = new;
        }
        i++;
    }
    return head;
}

struct  node* concat(struct node *head1 , struct node *head2)
{
    struct node *temp = head1;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    temp->next = head2;
    return head1;
}

struct node* sort(struct node *head2)
{
    int t;
    struct node *temp = head2;
    struct node *pres;
    while(temp->next != NULL)
    {
        pres = temp->next;
        while(pres != NULL)
        {
            if(pres->data < temp->data)
            {
                t = pres->data;
                pres->data = temp->data;
                temp->data = t;
            }
            pres = pres->next;
        }
        temp = temp->next;
    }
    return head2;
}

struct node* reverse(struct node *head2)
{
    struct node *prev = head2;
    struct node *pres = prev->next;
    prev->next = NULL;
    struct node *temp = pres;
    while(temp->next != NULL)
    {
        temp = pres->next;
        pres->next = prev;
        prev = pres;
        pres = temp;
    }
    pres->next = prev;
    head2 = pres;
    return head2;
}

void display(struct node *head)
{
    struct node *temp = head;
    printf("\nLinked List ELements: ");
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
