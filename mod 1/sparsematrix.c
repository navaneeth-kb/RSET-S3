#include<stdio.h>
void matrix(int a[20][20],int r,int c);
void sparse(int a[20][20],int r,int c,int s[20][20]);
void add(int sparsea[20][20],int sparseb[20][20],int s[20][20]);
void transpose(int a[20][20]);



void matrix(int a[20][20],int r,int c)
{
 int i,j;
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   printf("Enter the elements:");
   scanf("%d",&a[i][j]);
  }
 }
}


void sparse(int a[20][20],int r,int c,int s[20][20])
{
 s[0][0]=r;
 s[0][1]=c;
 int count=0;
 int z=1,i,j;
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   if(a[i][j]!=0)
   {
    s[z][0]=i;
    s[z][1]=j;
    s[z][2]=a[i][j];
    z++;
    count++;
   }
  }
 }
 s[0][2]=count;
 display(s,z);
 
}


void add(int sparsea[20][20],int sparseb[20][20],int s[20][20])
{
 if(sparsea[0][0]==sparseb[0][0] && sparsea[0][1]==sparseb[0][1])
 {
  s[0][0]=sparsea[0][0];
  s[0][1]=sparsea[0][1];
  int i=1,j=1,k=1,count=0;
  while(i<=sparsea[0][2] && j<=sparseb[0][2])
   {
     if(sparsea[i][0]>sparseb[j][0])
     {
		 s[k][0]=sparseb[j][0];
		 s[k][1]=sparseb[j][1];
		 s[k][2]=sparseb[j][2];
		 j++;
		 k++;
		 count++;
	 }
	 else if(sparsea[i][0]<sparseb[j][0])
     {
		 s[k][0]=sparsea[i][0];
		 s[k][1]=sparsea[i][1];
		 s[k][2]=sparsea[i][2];
		 i++;
		 k++;
		 count++;
	 }
	 else
	 {
		 if(sparsea[i][1]>sparseb[j][1])
         {
		     s[k][0]=sparseb[j][0];
		     s[k][1]=sparseb[j][1];
			 s[k][2]=sparseb[j][2];
			 j++;
			 k++;
			 count++;
		 }
		 else if(sparsea[i][1]<sparseb[j][1])
		 {
			 s[k][0]=sparsea[i][0];
			 s[k][1]=sparsea[i][1];
			 s[k][2]=sparsea[i][2];
			 i++;
			 k++;
			 count++;
	     }
	     else
	     {
			 s[k][0]=sparsea[i][0];
			 s[k][1]=sparsea[i][1];
			 s[k][2]=sparsea[i][2]+sparseb[j][2];
			 i++;
			 j++;
			 k++;
			 count++;
		 }
	}
   }
	while(i<=sparsea[0][2])
	{
		s[k][0]=sparsea[i][0];
		s[k][1]=sparsea[i][1];
		s[k][2]=sparsea[i][2];
		i++;
		k++;
		count++;
	}
	while(j<=sparseb[0][2])
	{
		s[k][0]=sparseb[j][0];
		s[k][1]=sparseb[j][1];
		s[k][2]=sparseb[j][2];
		j++;
		k++;
		count++;
	}
   s[0][2]=count;
   display(s,k);
   }
  else
  {
	  printf("The sparse matrix cannot be added");
  }
}

void display(int a[20][20],int k)
{
 int i,j;
 for(i=0;i<k;i++)
 {
	 for(j=0;j<3;j++)
	 {
		 printf("%d\t",a[i][j]);
	 }
	 printf("\n");
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
			








void main()
{
	int ch,a[20][20],b[20][20],r1,r2,c1,c2,s1[20][20],s2[20][20],s[20][20];
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
				   matrix(a,r1,c1);
				   sparse(a,r1,c1,s1);
				   break;
		  case 2:printf("Enter the number of rows of matrix 2:");
				   scanf("%d",&r2);
				   printf("Enter the number of columns of matrix 2:");
				   scanf("%d",&c2);
				   matrix(b,r2,c2);
				   sparse(b,r2,c2,s2);
				   break;
		  case 3:add(s1,s2,s);
				  break;
		  case 4:transpose(s);
		          break;
		  case 5:return(0);
		  default:printf("Inavalid choice");
	     }
	 }
} 
	



  
	
		
	
		
		 
	
    



