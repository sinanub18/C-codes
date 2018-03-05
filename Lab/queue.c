/*#include<stdio.h>
#define size 5
int q[size],front=-1,rear=-1;
void insert();
void delete();
void disp();
void main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	int ch;
	while(1)
	{
	printf("Enter your choice\n");
	printf("1: Enqueue\n");
	printf("2: Dequeue\n");
	printf("3: Display\n");
	printf("4: Exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		insert();
		break;
	case 2:
		delete();
		break;
	case 3:
		disp();
		break;
	case 4:
		exit(0);
		break;
	default:
		printf("Invalid Choice\n");
		}
	}
}
void insert()
{
	int value;
	if(rear==(size-1))
	{
		printf("Queue is full\n");
	}
	else
		printf("Enter the value you want to enqueue\n");
		scanf("%d",&value);
		rear++;
		q[rear]=value;
}
void delete()
{
	if(front==rear)
	{
		printf("Queue is  empty\n");
	}
	else
	printf("Deleted element is %d\n",q[front]);
	front++;
}
void disp()
{
	int i;
	if(front==rear)
	{
		printf("Queue is Empty\n");
	}
	else
		printf("Queue elements are\n");
		for(i=front;i<=rear;i++)
		{
			printf("%d\n",q[i]);
	}
}
*/
