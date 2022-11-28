#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char stack[100];
int top=-1;

char* evaluate(char[],char[]);
void push(char[],char);
char pop(char[]);
int precedence(char);

int main()
{
    char infix[100],postfix[100];
    printf("Enter the infix expression: ");
    scanf("%s",infix);
    strcpy(postfix,"");
    printf("\nPostfix Expression: %s",evaluate(infix,postfix));
    return 0;
}

char* evaluate (char infix[],char postfix[])
{
    int i=0,j=0;
    char t;
    while(infix[i]!='\0')
    {
        if(infix[i]=='(')
        {
            push(stack,infix[i]);
            i++;
        }
        else if(infix[i]==')')
        {
            if(top==-1)
            {   printf("Invalid Expression");
                exit(0);
            }
            while(stack[top]!='(')
            {
                postfix[j]=pop(stack);
                j++;
            }
            t=pop(stack);
            i++;
        }
        else if(isalnum(infix[i]))
        {
            postfix[j]=infix[i];
            j++;
            i++;
        }
        else if((infix[i]=='+')||(infix[i]=='-')||(infix[i]=='*')||(infix[i]=='/')||(infix[i]=='%'))
        {
            while((top!=-1)&&(stack[top]!='(')&&((precedence(stack[top])>(precedence(infix[i])))))
            {
                postfix[j]=pop(stack);
                j++;
            }
            push(stack,infix[i]);
            i++;
        }
        else
        {
            printf("Invalid element in expression");
            exit(0);
        }
    }
    while((top!=-1)&&(stack[top]!='('))
    {
        postfix[j]=pop(stack);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}

void push(char stack[],char ele)
{
    if(top==99)
    {
        printf("Overflow");
    }
    else
    {
        top++;
        stack[top]=ele;
    }
}

char pop(char stack[])
{
    char t;
    if(top==-1)
    {
        printf("Underflow");
    }
    else
    {
        t = stack[top];
        top--;
        return t;
    }
}

int precedence(char e1)
{
    if((e1=='*')||(e1=='/')||(e1=='%'))
        return 1;
    else if((e1=='+')||(e1=='-'))
        return 0;
}
