#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[50];front=-1,rear=-1,max=0,count=0;;
void main()
{
	int ch,val;
	printf("Enter the limit of the array:");
	scanf("%d",&max);
	while(1)
	{	printf("\n");
		printf("1-INSERT  2-DELETE  3-Is_empty  4-Is_full  5-DISPLAY  6-EXIT");
		printf("\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter value to be inserted:");
			scanf("%d",&val);
			insert(val);
			break;

			case 2:
			delete();
			break;

			case 3:
			isEmpty();
			break;

			case 4:
			isFull();
			break;

			case 5:
			display();
			break;

			case 6:
			return 0;
		}
	}
}

void insert(int value)
{
	
	if(front==-1 && rear==-1)
	{
		front=rear=0;
		a[rear]=value;
		rear++;
		count++;
	}
	else if(front==(rear+1)%max)
	{
		printf("Stack overflow");
	}
	else
	{
		a[rear]=value;
		rear=(rear+1)%max;
	}
}

void delete()
{
	if(rear==front%max)
	{
		printf("Queue is empty");
		front=rear=-1;
	}
	else
	{
		front=(front+1)%max;
		count--;
	}
}

void display()
{
	int i;
	i=front;
	if(rear==-1 && front==-1)
	{
		printf("Queue is empty");
	}
	else
	{
		printf("%d\t",a[i]);
		i++;
		while(i!=rear)
		{	
			printf("%d\t",a[i]);
			i=(i+1)%max;
		}
	}
}

void isFull()
{
	if (front==-1 && count==max)
	{	
		printf("Queue is full");
	}
	else 
	{
		printf("Queue is not full");
	}
}

void isEmpty()
{
	if (front==-1 && rear==max)
	{	
		printf("Queue is empty");
	}
	else 
	{
		printf("Queue is not empty");
	}
}
	
