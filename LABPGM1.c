#include <stdio.h>
void push();
void pop();
void peek();
int N=5;
int stack[5];
int top=-1;
int main()
{
int ch;

do
{printf("Enter your choice:1(push)/2(pop)/3(peek)/4(exit):\n");
scanf("%d",&ch);
    switch(ch)
{
case 1 :
    push();
    break;
case 2 :
    pop();
    break;
case 3 :
    peek();
    break;
case 4:
    break;
default :
    printf("choice is out of range");
    break;
}
}while(ch!=4);
return 0;
}
void push()
{
int x;
printf("enter data:");
scanf("%d",&x);
if(top==N-1)
{
printf("overflow..cannot enter data\n");
}
else
{
top++;
stack[top]=x;
}
}
void pop()
{
int item;
if(top==-1)
{
printf("underflow...stack is empty\n");
}
else
{
item=stack[top];
top--;
printf("%d",item);
printf("\n");
}
}
void peek()
{
if(top==-1)
{
printf("underflow...\n");
}
else
{
printf("%d\n",stack[top]);
printf("\n");
}
}
