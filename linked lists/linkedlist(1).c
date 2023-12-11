#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *ptr,*head=NULL,*temp;
void insertion_End()		//at end
{
    if (head==NULL)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter the value:");
        scanf("%d",&temp->data);
        temp->link=NULL;
        head=temp;
    }
    else
    {
        ptr=head;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter value");
        scanf("%d",&temp->data);
        temp->link=NULL;
        ptr->link=temp;
    }
}
void insertion_Spec()            		//at specified node
{
    int i;
    printf("Enter node value after which you want to insert:");
    scanf("%d",&i);
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value:");
    scanf("%d",&temp->data);
    temp->link=NULL;
    ptr=head;
    while (ptr->data!=i)
    {
        ptr=ptr->link;
    }
    temp->link=ptr->link;
    ptr->link=temp;
}
void insertion_Beg()				//at beginning
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value:");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if (head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->link=head;
        head=temp;
    }
}
void deletion1()
{
    ptr=head;
    if (ptr==NULL)
    {
        printf("Deletion not possible");
        return NULL;
    }
    ptr=ptr->link;
    printf("deleted node is %d",head->data);
    head=ptr;
}
void deletion2()  //at end
{
    ptr=head;
    if (ptr==NULL)
    {
        printf("Deletion not possible");
    }
    else if(ptr->link==NULL)  //only one node
    {
        printf("The node deleted is %d",ptr->data);
        head=NULL;
    }
    else
    {
        while(ptr->link->link!=NULL)
        {
            ptr=ptr->link;
        }
        printf("The node deleted is %d",ptr->link->data);
        ptr->link=NULL;
    }
}
void deletion3()
{
     int i;
    printf("Enter node value which you want to delete:");
    scanf("%d",&i);
    ptr=head;
    if (ptr==NULL)
    {
        printf("Deletion not possible");
    }
    else if(ptr->link==NULL && ptr->data==i)  //only one node
    {
        printf("The node deleted is %d",ptr->data);
        head=NULL;
    }
     else if(ptr->data==i)  //first node
    {
        printf("The node deleted is %d",head->data);
        ptr=ptr->link;
        head=ptr;
    }
    else
    {
	    while (ptr->link->data!=i)
	    {
		ptr=ptr->link;
	    }
	     printf("the node deleted is %d",ptr->link->data);
	     ptr->link=ptr->link->link;
	     //ptr->link->link=NULL;
     }
}
void display()
{
    ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
}
void main()
{
    int op;
    while(1)
    {
        printf("\n1.Insert at beginning   \n2.Insert at end     \n3.insert at specified node  \n4.Delete from beginning     \n5.Delete from End   \n6.Delete a specified node     \n7.Display  \n8.exit");
        printf("\nEnter choice:");
        scanf("%d",&op);
        switch(op)
        {
            case 1:insertion_Beg();
                    break;
            case 2:insertion_End();
                    break;
            case 3:insertion_Spec();
                    break;
            case 4:deletion1();
                    break;
            case 5:deletion2();
                    break;
            case 6:deletion3();
                    break;
            case 7:display();
                    break;
            case 8:exit(0);
        }
    }
}
