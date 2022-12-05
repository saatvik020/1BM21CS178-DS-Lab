#include<stdio.h>
#include<stdlib.h>
int q[100],n,i,c,rear=-1,front=-1,a;
void enqueue(void);
void dequeue(void);
void display(void);
int main()
{
    printf("Enter the size of queue:");
    scanf("%d",&n);
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    do{
    printf("Enter choice:");
    scanf("%d",&c);
    switch(c)
    {
        case 1:enqueue();
                break;
        case 2:dequeue();
                break;
        case 3:display();
                break;
        case 4:exit(0);
        default:printf("Invalid");
    }
    }while(c>0);
return 0;
}
void enqueue()
{
    printf("Enter element:");
    scanf("%d",&a);
    if(front==((rear+1)%n)&&front!=0)
        printf("Overflow\n");
    else if(front==-1)
    {
        front++;
        rear++;
        q[rear]=a;
    }
    else
    rear=(rear+1)%n;
    q[rear]=a;

}
void dequeue()
{
    if((front==rear) && (front!=0))
        printf("Underflow");
    else
    {
        printf("%d\n",q[front]);
        front=(front+1)%n;
    }
}
void display()
{
    i=front;
    while(i!=rear)
    {
        printf("%d\n",q[i]);
        i=(i+1)%n;
    }
    printf("%d\n",q[rear]);
}
