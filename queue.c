#include<stdio.h>
#include<stdlib.h>
void enqueue(void);
void dequeue(void);
void display(void);
int q[100];
int front=-1,rear=-1,x,y,i,a,b;
int main()
{
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    do{
    printf("Enter choice:");
    scanf("%d",&x);
    switch(x){
    case 1:enqueue();
            break;
    case 2:dequeue();
            break;
    case 3:display();
            break;
    case 4: exit(0);
    default:printf("Invalid choice");
    }
    }while(x>0);
    return 0;
}
void enqueue()
{
    printf("Enter the element to be added:");
    scanf("%d",&a);
    if (front==-1){
        front++;
        rear++;
        q[rear]=a;
    }
    else if(front<=99)
    {
        rear++;
        q[rear]=a;
    }
    else{
        printf("Queue overflow");
    }
}
void dequeue()
{
    if(front==-1||front>rear)
        printf("Queue underflow");
    else{
        printf("%d\n",q[front]);
        front++;
    }
}
void display()
{
    for(i=front;i<=rear;i++)
    {
        printf("%d\n",q[i]);
    }
}
