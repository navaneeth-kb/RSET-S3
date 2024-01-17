#include <stdio.h>
#include <stdlib.h>
void display(int m[20][20],int k)
{
    int i,j;
    for(i=0;i<k;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
}
void input_mat(int m[20][20],int r ,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("input element:");
            scanf("%d",&m[i][j]);
        }
    }
}
void convert_sparse(int s[20][20],int m[20][20],int r,int c)
{
    s[0][0]=r;
    s[0][1]=c;
    int count=0,i,j,k=1;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(m[i][j]!=0)
            {
                s[k][0]=i;
                s[k][1]=j;
                s[k][2]=m[i][j];
                k++;
                count++;
            }
        }
    }
    s[0][2]=count;
    display(s,k);
}
void add_sparse(int sum[20][20],int s1[20][20],int s2[20][20])
{
    if(s1[0][0]==s2[0][0] && s1[0][1]==s2[0][1])
    {
        sum[0][0]=s1[0][0];
        sum[0][1]=s1[0][1];
        int i=1,j=1,k=1,count=0;
        while(i<=s1[0][2] && j<=s2[0][2])
        {
            if (s1[i][0]>s2[j][0])
            {
                sum[k][0]=s2[j][0];
                sum[k][1]=s2[j][1];
                sum[k][2]=s2[j][2];
                j++;
                k++;
                count++;
            }
            else if (s1[i][0]<s2[j][0])
            {
                sum[k][0]=s1[i][0];
                sum[k][1]=s1[i][1];
                sum[k][2]=s1[i][2];
                i++;
                k++;
                count++;
            }
            else
            {
                if (s1[i][1]>s2[j][1])
                {
                    sum[k][0]=s2[j][0];
                    sum[k][1]=s2[j][1];
                    sum[k][2]=s2[j][2];
                    j++;
                    k++;
                    count++;
                }
                else if (s1[i][1]<s2[j][1])
                {
                    sum[k][0]=s1[i][0];
                    sum[k][1]=s1[i][1];
                    sum[k][2]=s1[i][2];
                    i++;
                    k++;
                    count++;
                }
                else
                {
                    sum[k][0]=s1[i][0];
                    sum[k][1]=s1[i][1];
                    sum[k][2]=s1[i][2]+s2[j][2];
                    i++;
                    j++;
                    k++;
                    count++;
                }
            }

        }
        while(i<=s1[0][2])
        {
            sum[k][0]=s1[i][0];
            sum[k][1]=s1[i][1];
            sum[k][2]=s1[i][2];
            i++;
            k++;
            count++;
        }
        while(j<=s2[0][2])
        {
            sum[k][0]=s2[j][0];
            sum[k][1]=s2[j][1];
            sum[k][2]=s2[j][2];
            j++;
            k++;
            count++;
        }
        sum[0][2]=count;
        display(sum,k);
    }
    else
    {
        printf("deletion not possible");
    }
}
void transpose(int a[20][20])
{
	int i,j,t[10][10];
	t[0][0]=a[0][1];
	t[0][1]=a[0][0];
	t[0][2]=a[0][2];
	for(i=1;i<=a[0][2];i++)
	{
	 t[i][0]=a[i][1];
	 t[i][1]=a[i][0];
	 t[i][2]=a[i][2];
    }
    for(i=0;i<=t[0][2];i++)
    {
		for(j=0;j<3;j++)
		{
			printf("%d\t",t[i][j]);
	    }
        printf("\n");
    }
}
/*void transpose(int m[20][20])
{
    int tran[20][20],k=1;
    tran[0][0]=m[0][0];
    tran[0][1]=m[0][1];
    tran[0][2]=m[0][2];
    int b=m[0][1];
    int n=m[0][2];
    for(int i=0;i<b;i++)
    {
        for(int j=1;j<n;j++)
        {
            if (m[i][j]==i)
            {
                tran[k][0]=m[j][1];
                tran[k][1]=m[j][0];
                tran[k][2]=m[j][2];
                k++;
            }
        }
    }
    display(tran,k);
}*/
void main()
{
	int ch,m1[20][20],m2[20][20],r1,r2,c1,c2,s1[20][20],s2[20][20],sum[20][20];
	while(1)
	{
		printf("\n1.Create matrix 1 and find sparse matrix\n");
	    printf("2.Create matrix 2 and find sparse matrix\n");
		printf("3.Addition of the 2 sparse matrices\n");
		printf("4.Transpose of the sum matrix\n");
		printf("5.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		  case 1:printf("Enter the number of rows of matrix 1:");
				   scanf("%d",&r1);
				   printf("Enter the number of columns of matrix 1:");
				   scanf("%d",&c1);
				   input_mat(m1,r1,c1);
				   convert_sparse(s1,m1,r1,c1);
				   break;
		  case 2:printf("Enter the number of rows of matrix 2:");
				   scanf("%d",&r2);
				   printf("Enter the number of columns of matrix 2:");
				   scanf("%d",&c2);
				   input_mat(m2,r2,c2);
				   convert_sparse(s2,m2,r2,c2);
				   break;
		  case 3:add_sparse(sum,s1,s2);
				  break;
		  case 4:transpose(sum);
		          break;
		  case 5:return(0);
		  default:printf("Inavalid choice");
                    break;
	     }
	 }
}
