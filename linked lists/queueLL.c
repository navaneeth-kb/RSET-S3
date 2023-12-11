#include <stdio.h>
#include <stdlib.h>

struct node
{
  	int data;
  	struct node* link;
};

struct node *front = NULL;
struct node *rear = NULL;
int count=0,max=0;
void enqueue(int d)
{
  	struct node* newnode;
  	newnode = (struct node*)malloc(sizeof(struct node));
 	newnode->data = d;
  	newnode->link = NULL;
  	count++;
  	if((front == NULL)&&(rear == NULL))
  	{
  	  front = rear = newnode;
  	}
  	else
  	{
		rear->link = newnode;
    		rear = newnode;
  	}
}

void display()
{
  struct node* temp;
  if((front == NULL)&&(rear == NULL)){
    printf("\nQueue is Empty");
  }
  else{
    temp = front;
    while(temp!=NULL)
    {
      printf(" %d ",temp->data);
      temp = temp->link;
    }
  }
}

void dequeue()
{
	struct node *temp;
	temp = front;
	if((front == NULL)&&(rear == NULL)||count==0)
	{
   		printf("\nQueue is Empty");
	}
  	else
	{
		printf("Element deleted is %d ",front->data);
		front = front->link;
		free(temp);
		count--;
	}
}
void main()
{
	int op,val;
	printf("Enter value of max:");
	scanf("%d",&max);
	printf("\n1.ENQUEUE   \n2.DEQUEUE   \n3.DISPLAY   \n4.EXIT");
	while(1)
	{
		printf("\nEnter choice:");
		scanf("%d",&op);
		switch(op)
		{
		      case 1:printf("Enter value:");
        		    scanf("%d",&val);
        		    if (count==max)
        		    {
        		      printf("Queue is full");
        		    }
        		    else
        		    {
        		      enqueue(val);
        		    }
     			    break;
      		      case 2:dequeue();
            		     break;
      		      case 3:display();
            		     break;
                      case 4:exit(0);
    	       }
  	}
}


