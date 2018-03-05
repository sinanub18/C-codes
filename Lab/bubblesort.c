/*#include<stdio.h>
int main()
{
	setvbuf(stdout,NULL,_IONBF,0);
	int a[40],n,i,j,temp;
	printf("How many elements you want to enter\n");
	scanf("%d",&n);
	printf("Enter the array element\n");
	for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<(n-i-1);j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;

			}
		}
	}
	printf("Sorted array in ascending order is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}*/
