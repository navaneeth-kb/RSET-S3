#include <stdio.h>
int n, a[50],b[50];
void merge(int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high)
    {
        if (a[i]<=a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++];
        }
    }
    if (i>mid)
    {
        for (int p=j;p<=high;p++)
        {
            b[k++]=a[p];
        }
   }
   else
   {
       for (int p=i;p<=mid;p++)
       {
           b[k++]=a[p];
       }
   }
   for (int p=low;p<=high;p++)
   {
       a[p]=b[p];
   }
}
void  mergesort(int p,int q)
{
    if (p<q)
    {  int m=(p+q)/2;
        mergesort(p,m);
        mergesort(m+1,q);
        merge(p,m,q);
    }
}
void main( )
{   printf("Enter max values:");
    scanf("%d",&n);
    printf("Enter array elements :");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(0,n-1);
    for (int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
