#include <stdio.h>
struct pqueue
{
	int value;
	int priority;
}a[10];
int front,rear,max;
void enqueue(int value,int priority)
{
	int i;
	int temp1,temp2;
	if (front==-1 && rear==-1)
	{
		front=rear=0;
		a[rear].value=value;
		a[rear].priority=priority;
		rear++;
	}
	else if (rear==max)
	{
		printf("Priority queue overflow");
	}
	else
	{
		a[rear].value=value;
		a[rear].priority=priority;
		for(i=rear;a[i].priority<a[i-1].priority;i--)
		{
			
			temp1=a[i].value;
			temp2=a[i].priority;
			a[i].value=a[i-1].value;
			a[i].priority=a[i-1].priority;
			a[i-1].value=temp1;
			a[i-1].priority=temp2;
		}
		rear++;
	}
}
void dequeue()
{
	int i;
	if(front==-1 && rear==-1)
	{
		printf("Queue empty");
	}
	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		for(i=1;i<rear;i++)
		{
			a[i-1].value=a[i].value;
			a[i-1].priority=a[i].priority;
		}
		rear=i-1;
	}
}
/*void display()
{
	int i=front%max;
	 if(front==-1 && rear==-1)
	{
		printf("Queue empty");
	}
	else
	{
		printf("%d",a[i]);
		i++;
		while(i!=rear)
		{
			printf("%d",a[i]);
			i=(i+1)%max;
		}
	}
}*/
void display()
{
	int i;
	if (front==-1 && rear==-1)
	{
		printf("Queue empty");
	}
	else 
	{
		for(i=front;i<rear;i++)
		{
			printf("%d\t",a[i].value);
		}
	}
}
void main()
{
	int val,pr,ch;
	front=rear=-1;
	printf("Enter the limit of the queue:");
	scanf("%d",&max);
	while(1)
	{
		printf("\n");
		printf("1-INSERT \n2-DELETE \n3-DISPLAY \n4-EXIT");
		printf("\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter the value:");
			scanf("%d",&val);
			printf("Enter its priority:");
			scanf("%d",&pr);
			enqueue(val,pr);
			break;
			
			case 2:
			dequeue();
			break;

			case 3:
			display();
			break;
		
			case 4:
			exit(0);
			
			case 5:
			printf("Invalid choice");
			break;
		}
	}
}

