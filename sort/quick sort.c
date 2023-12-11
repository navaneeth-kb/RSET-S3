#include<stdio.h>
#include<stdlib.h>
int n;
void QuickSort(int A[],int p,int r);
int partition(int A[],int p,int r);
void main()
{
	int A[100],i;
	printf("Enter the number of elements of the array\n");
	scanf("%d",&n);
	printf("Enter the elements of the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	}
	printf("The array before sorting is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",A[i]);
	}
	printf("\n");
	QuickSort(A,0,n-1);
	printf("The array after sorting is:\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",A[i]);
	}
	printf("\n");
}

void QuickSort(int A[],int p,int r)
{
	int j;
	if(p<r)
	{
		j = partition(A,p,r);
		QuickSort(A,p,j-1);
		QuickSort(A,j+1,r);
	}
}

int partition(int A[],int p,int r)
{
	int i,j,pivot,temp,k;
	i=p;
	j=r;
	pivot=p;
	while(i<j)
	{
		while(A[i]<=A[pivot])
		{
			i++;
		}
		while(A[j]>A[pivot])
		{
			j--;
		}
		if(i<j)
		{
			temp=A[i];
			A[i]=A[j];
			A[j]=temp;
			//for(k=0;k<n;k++)
			//		{
			// printf("%d\t",A[k]);
			//}
			// printf("\n");
		}
	}
	temp=A[j];
	A[j]=A[pivot];
	A[pivot]=temp;
	//for(k=0;k<n;k++)
	//{
	//printf("%d\t",A[k]);
	//}
	//printf("\n");
	return j;
}
