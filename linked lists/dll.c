#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node* next;
  struct node* prev;
};
struct node* ptr,*head=NULL,*temp,*ptr1;

void rearInsert(int value)
{
  if (head==NULL)
  {
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->prev=temp->next=NULL;
    head=temp;
  }
  else
  {
    ptr=head;
    while(ptr->next!=NULL)
    {
      ptr=ptr->next;
    }
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    ptr->next=temp;
    temp->prev=ptr;
  }
}
void frontInsert(int value)
{
  if (head==NULL)
  {
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->prev=temp->next=NULL;
    head=temp;
  }
  else
  {
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=head;
    head->prev=temp;
    head=temp;
  }
}
void nodeInsert(int value)
{
  int i,flag=0;
  printf("Enter node after which you want to insert:");
  scanf("%d",&i);
  ptr=head;
  if (head->data==i)
  {
    flag=1;
  }
    while(ptr->next!=NULL)
    {
      ptr=ptr->next;
      if (ptr->data==i)
      {
        flag=1;
      }
    }
    if (flag==0)
    {
      printf("node is not present");
    }
    else
    {
      ptr=head;
      while (ptr->data!=i)
      {
        ptr=ptr->next;
      }
      temp=(struct node*)malloc(sizeof(struct node));
      temp->data=value;
      ptr1=ptr->next;
      temp->prev=ptr;
      temp->next=ptr1;
      ptr->next=temp;
      if (ptr1 !=NULL)
      {
        ptr1->prev=temp;
      }
    }
}
void rearDelete()
{
  ptr=head;
  if (head==NULL)
  {
    printf("Empty");
  }
  else if (ptr->next==NULL)
  {
    printf("%d is deleted",ptr->data);
    ptr=head=NULL;
  }
  else
  {
    while(ptr->next->next!=NULL)
    {
      ptr=ptr->next;
    }
    printf("The node deleted is %d",ptr->next->data);
    ptr->next->prev=NULL;
    ptr->next=NULL;
  }
}
void frontDelete()
{
  ptr=head;
  if (head==NULL)
  {
    printf("Empty");
  }
  else if (ptr->next==NULL)
  {
    printf("%d is deleted",ptr->data);
    ptr=head=NULL;
  }
  else
  {
    ptr=ptr->next;
    ptr->prev=NULL;
    printf("Deleted node is %d",head->data);
    head=ptr;
  }
}
void nodeDelete()
{
  int i,flag=0;
  ptr=head;
  printf("Enter node value which you want to delete:");
  scanf("%d",&i);
  ptr=head;
  if (head->data==i)
  {
    flag=1;
  }
  while(ptr->next!=NULL)
    {
      ptr=ptr->next;
      if (ptr->data==i)
      {
        flag=1;
      }
    }
    ptr=head;
    while(ptr->data!=i)
    {
      ptr=ptr->next;
    }
    if (flag==0)
    {
      printf("node is not present");
    }
  else if (ptr->prev==NULL ||ptr==head)
  {
    printf("deleted node is %d",ptr->data);
    ptr=ptr->next;
    head=ptr;
    head->prev=NULL;
  }
  else if (ptr->next==NULL)
  {
    printf("deleted node is %d",ptr->data);
    ptr->prev->next=NULL;
    ptr=ptr->prev;
  }
  else
  {
    printf("deleted node is %d",ptr->data);
    ptr1=ptr->next;
    ptr=ptr->prev;
    ptr->next=ptr1;
    ptr1->prev=ptr;
  }
}
void forwardDisplay()
{
  ptr=head;
  while(ptr!=NULL)
  {
    printf("%d ",ptr->data);
    ptr=ptr->next;
  }
}
void rearDisplay()
{
  ptr=head;
  while(ptr->next!=NULL)
  {
    ptr=ptr->next;
  }
  while(ptr!=NULL)
  {
    printf("%d ",ptr->data);
    ptr=ptr->prev;
  }
}

void main()
{
  int op,val;
  printf("1.Rear insert \n2.Front insert  \n3.Insert at specified node \n4.Rear delete \n5.Front delete \n6.Delete specified node \n7.Forward Display \n8.Rear Display \n9.Exit");
  while(1)
  {
      printf("\nEnter choice:");
      scanf("%d",&op);
      switch(op)
      {
        case 1:printf("Enter value to insert:");
            scanf("%d",&val);
            rearInsert(val);
            break;
        case 2:printf("Enter value to insert:");
            scanf("%d",&val);
            frontInsert(val);
            break;
        case 3:printf("Enter value to insert:");
            scanf("%d",&val);
            nodeInsert(val);
            break;
        case 4:rearDelete();
            break;
        case 5:frontDelete();
            break;
        case 6:nodeDelete();
            break;
        case 7:forwardDisplay();
            break;
        case 8:rearDisplay();
            break;
        case 9:exit(0);
      }
   }
}
