#include <stdio.h>
#include <stdlib.h>
int a[50],n,ele,low,high;
void display()
{
    
    for (int i=0;i<n;i++)
    {
        printf( "%d\t", a[i]);
    }
}
void sort()//for binary search
{
   for (int i=0;i<n-1;i++)
   {
       for(int j=0;j<n-1-i;j++)
       {
           if (a[j]>a[j+1])
           {
               int temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
           }
       }
   }
}
void ls()
{ int flag=0;
    for (int i=0;i<n; i++)
    {
        if (a[i]==ele)
        {
            printf("\nElement found at position :\t%d",i+1);
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("\nElement not found");
    }
    
}
void bs()
{
    low=0;high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if (a[mid]==ele)
        {
            printf("\n%d present ",ele);
            break;
        }
        else if (ele>a[mid])
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if (low>high)
    {
        printf("\n%d not present ",ele);
    }
    display();
}
void main()
{
    printf("Enter max value:");
    scanf("%d",&n);
       printf("Enter array elements:");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    int ch;
    while(ch!=3)
    {  printf("\nEnter element to be searched:\t");
        scanf("%d",&ele);
        printf("\n-------MENU-------- \n1.)LINEAR SEARCH\n2.)BINARY SEARCH\n3.)EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                            ls();
				break;
            case 2:
                            sort();
                            bs();
			break;
        }
    }
}
