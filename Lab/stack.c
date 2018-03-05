/*#include<stdio.h>
void push();
void pop();
void peek();
void disp();
int stack[5], top=-1, cap=5;
int main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	int ch;
	while(1)
	{
		printf("Enter your choice:\n");
		printf("1: PUSH\n");
		printf("2: POP\n");
		printf("3: PEEK\n");
		printf("4: DISPLAY\n");
		printf("5: Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
				push();
				break;
		case 2:
				pop();
				break;
		case 3:
				peek();
				break;
		case 4:
				disp();
				break;
		case 5:
				exit(0);
				break;
		default:
			printf("Invalid Input\n");
		}
	}
}
void push()
{
	int n;
	if(top==(cap-1))
	{
		printf("Stack is Full\n");
	}
	else
	{
		printf("Enter the element to push\n");
		scanf("%d",&n);
		stack[++top]=n;
	}
}
void pop()
{
	//int n;
	if(top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Element %d is Popped from Stack\n",stack[top]);
		top--;
	}
}
void peek()
{
	if(top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Top element in stack is %d\n",stack[top]);
	}
}
void disp()
{
	int i,n;
	n=top;
	printf("Stack elements are\n");
	for(i=0;i<=n;i++)
	{
		printf("%d\n",stack[i]);
	}
}*/


