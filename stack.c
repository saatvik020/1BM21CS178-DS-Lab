#include<stdio.h>
#include<conio.h>
int top=-1,c,stack[100];
void push(void);
void pop(void);
void display(void);
int main()
{
    do
    {
        printf("Enter choice:\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&c);
        switch(c)
        {
        case 1: push();
                break;
        case 2: pop();
                break;
        case 3:display();
                break;
        case 4:exit(0);
        default: printf("Invalid");
        }
    }while(c>0);
    return 0;

}
void push()
{
    if(top<100)
    {
        top++;
        printf("Enter element:");
        scanf("%d",&stack[top]);
    }
    else printf("Stack overflow");
}
void pop()
{
    if (top>-1)
    {
     printf("%d\n",stack[top]);
     top--;
    }
    else printf("Stack empty");
}
void display()
{
    do
    {
        printf("%d\n",stack[top]);
        top--;
    }while(top>-1);
}
