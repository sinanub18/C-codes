/*
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct linkedlist
{
	int info;
	struct linkedlist *link;
};
typedef struct linkedlist node;
node *first=NULL;

node * insert_front(node *first,int ele)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	if(temp==NULL)
	{
		printf("No sufficient memory\n");
		return NULL;
	}
	temp->info=ele;
	temp->link=first;
	first=temp;
	return first;
}

node *insert_rear(node *first,int ele)
{
	node *temp,*cur;
	temp=(node*)malloc(sizeof(node));
	if(temp==NULL)
	{
		printf("No sufficient memory\n");
		return NULL;
	}
	temp->info=ele;
	temp->link=NULL;
	if(first==NULL)
		return temp;
	cur=first;
	while(cur->link!=NULL)
		cur=cur->link;
	cur->link=temp;
	return first;
}

node *delete_front(node *first)
{
	node *temp;
	if(first==NULL)
	{
		printf("Empty List\n");
		return NULL;
	}
	if(first->link==NULL)
	{
		printf("\n Element deleted=%d\n",first->info);
		free(first);
		return NULL;
	}
	temp=first;
	printf("\n Deleted element=%d\n",temp->info);
	first=first->link;
	free(temp);
	return first;
}

node *delete_rear(node *first)
{
	node *temp,*prev,*cur;
	if(first==NULL)
	{
		printf("\n List Empty");
		return NULL;
	}
	if(first->link==NULL)
	{
		printf("\n Element deleted=%d\n",first->info);
		free(first);
		return NULL;
	}

	prev=NULL;
	cur=first;
	while(cur->link!=NULL)
	{
		prev=cur;
		cur=cur->link;
	}
	prev->link=NULL;
	printf("\n Deleted element=%d\n",cur->info);
	free(cur);
	return first;
}

void display(node *first)
{
	node *temp;
	if(first==NULL)
	{
		printf("Empty list");
		return ;
	}
	temp=first;
	while(temp!=NULL)
	{
		printf("%d->",temp->info);
		temp=temp->link;
	}
}


void main()
{
	int ele,ch;
	setvbuf(stdout,NULL,_IONBF,0);
	while(1)
	{
		printf("\nEnter your choice:");
		printf("\n1: Insert Front 2: Insert Rear 3: Delete Front\n");
		printf("4: Delete Rear 5: Display 6: exit:\n");

		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("\nEnter the element to be inserted:");
			scanf("%d",&ele);
			first=insert_front(first,ele);
			break;
		case 2:
			printf("\nEnter the element to be inserted:");
			scanf("%d",&ele);
			first=insert_rear(first,ele);

			break;
		case 3:
			first=delete_front(first);
			break;
		case 4:
			first=delete_rear(first);
			break;
		case 5:
			display(first);
			break;
		case 6:exit(0);

		}
	}
	getch();
}

*/
