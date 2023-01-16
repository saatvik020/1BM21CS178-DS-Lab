#include<stdio.h>
struct node{
    int data;
    struct node *next,*prev;
};
struct node *head=NULL;
struct node *tail=NULL;

void createlist(int n){
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    printf("Enter data to be entered:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    head=newnode;
    struct node *temp=head;
    for(int i=1;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data to be entered:");
        scanf("%d",&newnode->data);
        temp->next=newnode;
        newnode->prev=temp;
        temp=temp->next;
    }
    newnode->next=NULL;
    tail=newnode;
}

void insertatfront(){
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    printf("Enter data to be entered:");
    scanf("%d",&newnode->data);
    head->prev=newnode;
    newnode->next=head;
    head=newnode;
}

void insertatend(){
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    printf("Enter data to be entered:");
    scanf("%d",&newnode->data);
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    tail->next=NULL;
}

void inserttoleft(int data){
    struct node *newnode;
    newnode=malloc(sizeof(struct node));
    printf("Enter data to be entered:");
    scanf("%d",&newnode->data);
    struct node *temp=head;
    while(temp->data!=data){
        temp=temp->next;
    }
    newnode->next=temp;
    newnode->prev=temp->prev;
    temp->prev->next=newnode;
    temp->prev=newnode;
}

void deleteatfront(){
    struct node *temp=head;
    temp->next->prev=NULL;
    head=temp->next;
    free(temp);
}

void deleteatend(){
    struct node *temp=tail;
    tail->prev->next=NULL;
    tail=tail->prev;
    free(temp);
}

void deleteatpos(int data){
    struct node *temp=head;
    while(temp->data!=data&& temp->next!= NULL){
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}

void display(){
    int i=1;
    struct node *temp=head;
    while(temp!=NULL){
        printf("Node %d : %d\n",i,temp->data);
        temp=temp->next;
        i++;
    }
}

int main(){
    int c,n,data;
    printf("1.Create list\n2.Insert at front\n3.Insert at end\n4.Insert to left\n5.Delete at front\n6.Delete at end\n7.Delete at a position\n8.Display\n9.Exit\n");
    do{
        printf("Enter choice:");
        scanf("%d",&c);
        switch(c){
            case 1: printf("Enter no of nodes:");
                    scanf("%d",&n);
                    createlist(n);
                    break;
            case 2: insertatfront();
                    break;
            case 3:insertatend();
                    break;
            case 4: printf("Enter datapoint left of which node to be inserted:");
                    scanf("%d", &data);
                    inserttoleft(data);
                    break;
            case 5: deleteatfront();
                    break;
            case 6: deleteatend();
                    break;
            case 7: printf("Enter datapoint of node to be deleted:");
                    scanf("%d", &data);
                    deleteatpos(data);
                    break;
            case 8:display();
                    break;
            case 9:exit(0);
            default:printf("Invalid choice");
        }
    }while(c>0);
    return 0;
}
