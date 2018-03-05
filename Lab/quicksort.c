/*#include<stdio.h>
int first,last,a[20];
void quicksort(int x[],int first,int last);
void main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	int i,n;
	printf("Enter the array length\n");
	scanf("%d",&n);
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quicksort(a[n],first,last);
	printf("Sorted array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
void quicksort(int x[20],int first,int last)
{
	int pivot,temp,i,j;
	if(first<last)
	{
		pivot=last;
		i=first;
		j=last;
		while(i<j)
		{
			while(x[i]<=x[pivot]&&i<last)
			i++;
			while(x[j]>x[pivot])
				j--;
			if(i<j)
			{
				temp=x[i];
				x[i]=x[j];
				x[j]=temp;
			}
		}
		temp=x[pivot];
		x[pivot]=x[j];
		x[j]=temp;
		quicksort(x,first,j-1);
		quicksort(x,j+1,last);
	}
}
*/


