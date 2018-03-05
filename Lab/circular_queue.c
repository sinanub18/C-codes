/*#include<stdio.h>
#define size 10
int front=-1,rear=-1,cq[size],element;
void insert();
void delete();
void main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	int ch;
	while(1)
	{
		printf("Enter your choice\n");
		printf("1: To insert an element\n");
		printf("2: To delete an element\n");
		printf("3:Exit");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("Enter an element to insert in queue\n");
			scanf("%d",&element);
			insert(element);
			break;
		case 2:
			delete();
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("Invalid Choice\n");
		}
	}
}
void insert(int element)
{
	if((rear==size-1)||(front==rear))
	{
		printf("Queue is full\n");
	}
	else if(front==-1&&rear==-1)
	{
		front=rear=0;
		cq[rear]=element;
	}
	else if(rear==size-1)
	{
		rear=0;
		cq[rear]=element;
	}
	else
	{
		rear++;
		cq[rear]=element;
	}
}
void delete()
{
	if(front==-1&&rear==-1)
	{
		printf("Queue is empty\n");
	}
	else if(front==rear)
	{
		element=cq[front];
		front=rear-1;
	}
	else if(front==size-1)
	{
		element=cq[front];
		front=0;
	}
	else
	{
		element=cq[front];
		front++;
	}
}*/
