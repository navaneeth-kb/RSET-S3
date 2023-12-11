#include <stdio.h>
#include <stdlib.h>

int a[20],max,front,rear;

void enqueue(int value)
{
    if (rear==max-1)
    {
        printf("Queue is Full");
    }
    else if (rear==-1)
    {
        front=0;
        rear=0;
        a[rear]=value;
    }
    else
    {
        rear++;
        a[rear]=value;
    }
}

void dequeue()
{
    if (front==-1)
    {
        printf("Queue is Empty");
    }
    else if (front==rear)
    {
        printf("Deleted element is %d",a[front]);
        front=-1;
        rear=-1;
    }
    else
    {
        printf("Deleted element is %d",a[front]);
        front++;
    }
}

void display()
{
    if (front==-1)
    {
        printf("Queue is Empty");
    }
    else
    {
        for (int i=0;i<=rear;;i++)
        {
            printf("%d\t",a[i]);
        }
    }
}

void main()
{
    int value,ch;
    front=-1;
    rear=-1;
    printf("Enter size of queue:");
    scanf("%d",&max);
    while (1)
    {
        printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
        printf("Enter choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter element to be inserted:");
                scanf("%d",&value);
                enqueue(value);
                break;
            
            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("INVALID CHOICE!!!");
        }   
    }
}