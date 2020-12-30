#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
int a[MAX]; //Stack
int top;

void display()
{

    printf("%d, ",top);

    if(isEmpty())
    {
        printf("Stack is Empty!");
        return;

    }
  printf("\nStack: ");
  for(int i=top;i>=0;i--)
    printf("%d, ",a[i]);

    printf("\n");

}
int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(top == MAX-1)
        return 1;
    else
        return 0;
}

int size()
{
    return top+1;
}


int pop()
{
    int x;
   if(isEmpty())
   {
 printf("Underflow!!");
   exit(1);
    }
x=a[top];
top = top-1;
return x;
}


void push(int x)
{
    if(isFull())
    {
        printf("Overflow!!");
        return;
    }
    top = top+1;
    a[top] = x;
}

int Stacktop ()
{    if(isEmpty())
{
    printf("Stack Underflow!");
    exit(1);
}
      return (a[top]);
}
int precedence(char symbol)
{
    switch(symbol)
    {
        case '(': return 0;
        case '+':
        case '-':return 1;
        case '<<':
        case '>>':return 3;

        case '*':
        case '/': return 2;
        case '^': return 3;

        default: return 0;
    }
}
void Initialize()
{
    top = -1;
}
void Infix_to_Postfix(char infix[],char postfix[])
{

    unsigned int i,p=0,x=0,y=0;
    char next,symbol;
    for ( i=0;i<strlen(infix);i++)
    {
        symbol=infix[i];
        if(symbol==' ' || symbol == '\t') //Ignore blanks and tabs
            {
                continue;
            }

   switch(symbol)
   {
       case '(': push(symbol);
                    x++;
                    break;
       case ')': y++;
                     while((next=pop())!='(')
                       postfix[p++] = next;
                       break;
       case '>>':
       case '<<':
       case '+':
       case '-':
       case '*':
       case '/':
       case '%':
       case '^':

                    while(!isEmpty() && precedence(a[top])>= precedence(symbol))
                    postfix[p++] = pop();
                    push(symbol);
                    break;




        default:
        postfix[p++] = symbol;

   }

}

    while (!isEmpty())
        postfix[p++]=pop();
    postfix[p]='\0';                        //Add '\0' to make postfix a string

}



void EvaluatePostfix(char postfix[])
{
    int x,y,result;

    for (int i=0;i<strlen(postfix);i++)
    {
        if(postfix[i]<='9' && postfix[i]>='0')
            push(postfix[i]-'0');
        else
        {
            switch(postfix[i])
            {

            case '+':  x=pop();
                       y=pop();
                       push(y+x);break;
            case '-':  x=pop();
                       y=pop();
                       push(y-x);break;
            case '*':  x=pop();
                        y=pop();
                        push(y*x);break;
            case '/':  x=pop();
                        y=pop();
                        push(y/x);break;
            case '%':  x=pop();
                       y=pop();
                       push(y%x);break;
            case '^':  x=pop();
                       push(x*x);break;
            case '<<':
                       x=pop();
                       y=pop();
                       push(y<<x);

                       break;
            case '>>':
                        x=pop();
                        y=pop();
                         push(y>>x);break;

            };
        }
    }
result = pop();
printf("%d",result);
}
int main()
{
    char infix[MAX],postfix[MAX];
    gets(infix);
    Infix_to_Postfix(infix,postfix);
    printf("%s\n",postfix);
   // EvaluatePostfix(postfix);
    return 0;
}
