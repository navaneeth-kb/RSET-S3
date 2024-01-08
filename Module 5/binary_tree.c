#include <stdio.h>
#include <stdlib.h>
int arr[100]={-1},count=0;
void inorder(int i)
{
    if(i<=count)
    {
        inorder(2*i);
        printf("%d",arr[i]);
        inorder(2*i+1);
    }
}
void preorder(int i)
{
    if(i<=count)
    {
        printf("%d",arr[i]);
        preorder(2*i);
        preorder(2*i+1);
    }
}
void postorder(int i)
{
    if(i<=count)
    {
        postorder(2*i);
        postorder(2*i+1);
        printf("%d",arr[i]);
    }
}
void insert(int value)
{
    count++;
    arr[count]=value;
}
void delete(int value)
{
    int i;
    while(arr[i]!=value)
    {
        i++;
    }
    arr[i]=arr[count];
    arr[count]=-1;
    count--;
}
void main()
{
    int ch,val;
    while(1)
    {
        printf("\n1-INSERT \n2-DELETE \n3-INORDER TRAVERSAL \n4-PREORDER TRAVERSAL \n5-POSTORDER TRAVERSAL\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter value:");
                    scanf("%d",&val);
                    insert(val);
                    break;
            case 2: printf("Enter value:");
                    scanf("%d",&val);
                    delete(val);
                    break;
            case 3: inorder(1);
                    break;
            case 4: preorder(1);
                    break;
            case 5: postorder(1);
                    break;
            case 6: exit(0);
        }
    }
}
