/*#include<stdio.h>
#include<string.h>
int f(char);
int g(char);
void main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	char infix[40], postfix[40];
	printf("Enter a valid infix expression\n");
	scanf("%s",infix);
	infix_postfix(infix,postfix);
	printf("The postfix expression\n");
	printf("%s\n",postfix);
}
int f(char symbol)
{
	switch(symbol)
	{
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 4;
	case '^':
	case '$':
		return 5;
	case '(':
		return 0;
	case '#':
		return -1;
	default:
		return 8;
	}
}
int g(char symbol)
{
	switch(symbol)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 3;
		case '^':
		case '$':
			return 6;
		case '(':
			return 9;
		case ')':
			return 0;
		default:
			return 7;
	}
}
void infix_postfix(char infix[],char postfix[])
{
	int top,j,i;
	char s[40];
	char symbol;
	top=-1;
	s[++top]='#';
	j=0;
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		while(f(s[top])>g(symbol))
		{
			postfix[j]=s[top--];
			j++;
		}
		if(f(s[top])!=g(symbol))
		{
			s[++top]=symbol;
		}
			else
				top--;
	}
		while(s[top]!='#')
		{
			postfix[j++]=s[top--];
		}
		postfix[j]='\0';
}
*/
