#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *ptr,*head=NULL,*temp;
void insertion_End()		
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
void insertion_Node()            		
{
    int i;

   /* for (ptr = head; ptr -> data != i; ) {
	ptr = ptr -> link;
    }
	if (ptr -> data != i) {
		printf("not present");
		return 0;
	}*/
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
void insertion_Beg()				
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
void deletion_beg()
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
void deletion_end()  
{
    ptr=head;
    if (ptr==NULL )
    {
        printf("Deletion not possible");
    }
    else if(ptr->link==NULL)  
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
void deletion_node()
{
     int i;
    printf("Enter node value which you want to delete:");
    scanf("%d",&i);
    ptr=head;
    /*if (ptr==NULL || ptr->data!=i)
    {
        printf("Deletion not possible");
    }
    else if(ptr->link==NULL && ptr->data==i)  
    {
        printf("The node deleted is %d",ptr->data);
        head=NULL;
    }
     else if(ptr->data==i)  
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
     }*/
	//gcydghc
	 if (ptr==NULL)
    {
        printf("Deletion not possible");
    }
   
     else if(ptr->data==i)  
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
	printf("\n");
        printf("\n1.INSERT AT BEGINNING  \n2.INSERT AT END     \n3.INSERT AT A SPECIFIED NODE  \n4.DELETE FROM BEGINNING     \n5.DELETE FROM END   \n6.DELETE A SPECIFIED NODE     \n7.DISPLAY  \n8.EXIT");
        printf("\nEnter choice:");
        scanf("%d",&op);
        switch(op)
        {
            case 1:insertion_Beg();
                    break;
            case 2:insertion_End();
                    break;
            case 3:insertion_Node();
                    break;
            case 4:deletion_beg();
                    break;
            case 5:deletion_end();
                    break;
            case 6:deletion_node();
                    break;
            case 7:display();
                    break;
            case 8:exit(0);
        }
    }
}
 
