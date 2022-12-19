#include<stdio.h>
struct node {
    int info;
    struct node *next;
};

struct node* head = NULL;

void createlist()
{
    int n;
    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);
    int data;
    struct node *newnode,*p;
    newnode = malloc(sizeof(struct node));
    head = newnode;
    p = head;
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
    head ->info = data;

    for (int i = 1; i < n; i++)
        {
        newnode = malloc(sizeof(struct node));
        p->next = newnode;
        printf("\nEnter number to be inserted : ");
        scanf("%d", &data);
        newnode->info = data;
        p = p->next;
        }
    p->next= NULL;
}
void traverse()
{
    int i=1;
    struct node* p;
    if (head== NULL)
        printf("\nList is empty\n");
    else {
        p = head;
        while (p != NULL) {
            printf("Node %d= %d\n",i,p->info);
            p = p->next;
            i++;
        }
    }
}
void insertatfront()
{
    int data;
    struct node* p;
    p = malloc(sizeof(struct node));
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
    p->next = head;
    head = p;
    head->info=data;
}
void insertatend()
{
    int data;
    struct node *p, *q;
    p = malloc(sizeof(struct node));
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
    p->next = NULL;
    p->info = data;
    q= head;
    while (q->next != NULL) {
        q= q->next;
    }
    q->next = p;
}
void insertatpos()
{
    int pos,data;
    struct node *p,*q,*newnode;
    printf("Enter data point before which node to be inserted:");
    scanf("%d",&pos);
    printf("Enter no to be inserted:");
    scanf("%d",&data);
    q=head;
    while(q->info!=pos)
    {
        p=q;
        q=q->next;
    }
    newnode=malloc(sizeof(struct node));
    newnode->info= data;
    p->next=newnode;
    newnode->next=q;
}
void deleteatfront()
{
    struct node *p, *q;
    q=head;
    p=head->next;
    head=p;
    free(q);
}
void deleteatend()
{
    struct node *p,*q;
    q=head;
    while(q->next!= NULL)
    {
        p=q;
        q=q->next;
    }
    p->next=NULL;
    free(q);
}
void deleteatpos()
{
    struct node *p,*q;
    int pos;
    printf("Enter data point of the node to be deleted:");
    scanf("%d",&pos);
    q=head;
    while(q->info!=pos)
    {
        p=q;
        q=q->next;
    }
     p->next=q->next;
     free(q);
}
int main()
{
    int c;
    printf("1.Create\n2.Display\n3.Insert at front\n4.Insert at end\n5.Insert at any position\n6.Delete at front\n7.Delete at end\n8.Delete at any position\n9.Exit\n");
    do{
    printf("Enter choice:");
    scanf("%d",&c);
    switch(c)
    {
        case 1:createlist();
                break;
        case 2:traverse();
                break;
        case 3:insertatfront();
                break;
        case 4: insertatend();
                break;
        case 5:insertatpos();
                break;
        case 6: deleteatfront();
                break;
        case 7: deleteatend();
                break;
        case 8: deleteatpos();
                break;
        case 9: exit(0);
        default: printf("Invalid choice");
    }
  }while(c>0);
  return 0;
}

