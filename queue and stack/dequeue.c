#include <stdio.h>
#include <stdlib.h>
int a[50],front=-1,rear=-1,max=0;
void main()
{
	int ch,val;
	printf("Enter the value for max:");
	scanf("%d",&max);
	while(1)
	{
		printf("\n");
		printf("1-Front insert  2-Rear insert  3-Front delete  4-Rear delete  5-Display ");
		printf("\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter value to be inserted:");
			scanf("%d",&val);
			frontInsert(val);
			break;
	
			case 2:
			printf("Enter value to be inserted:");
			scanf("%d",&val);
			rearInsert(val);
			break;
			
			case 3:
			deleteFront();
			break;
		
			case 4:
			deleteRear();
			break;

			case 5:
			display();
			break;

			case 6:
			return 0;

			default:
			printf("invalid choice");
			break;

		}
	}
}

void frontInsert(value)
{
	int i;
	if(front==0 && rear==max-1)
	{
		printf("Queue is full");
	}
	else if(rear==-1 && front==-1)
	{
		front=rear=0;
		a[front]=value;
	}
	else if(front>0)
	{
		front--;
		a[front]=value;
	}
	else
	{
		for(i=rear;i>=front;i--)
		{
			a[i+1]=a[i];
		}
		a[front]=value;
		rear++;
	}
}

void rearInsert(int value)
{
	int i;
	if(front==0 && rear==max-1)
	{
		printf("Queue is full");
	}
	else if(rear==-1 && front==-1)
	{
		front=rear=0;
		a[rear]=value;
	}
	else if(rear<max-1)
	{
		rear++;
		a[rear]=value;
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			a[i-1]=a[i];
		}
		a[rear]=value;
		front--;
	}			
}

void deleteFront()
{
	if(front==-1)
	{
		printf("DEqueue is empty");
	}
	else if(front==rear)
	{
		printf("Deleted element is %d",a[front]);
		front=rear=-1;
	}
	else
	{
		printf("Deleted element is %d",a[front]);
		front++;
	}
}

void deleteRear()
{	
	if(front==-1)
	{
		printf("DEqueue is empty");
	}
	else if(front==rear)
	{
		printf("Deleted element is %d",a[front]);
		front=rear=-1;
	}
	else
	{
		printf("Deleted element is %d",a[rear]);
		rear--;
	}
}

void display()
{
	int i;
	if(front==-1)
	{
		printf("Queue is empty");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",a[i]);
		}
	}
}


		

	

	
