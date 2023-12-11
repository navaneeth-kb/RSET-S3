#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top=-1,max;
char a[100],b[100],c[100];

void push(char n)
{
    top++;
    c[top]=n;
}

char pop()
{
    char value;
    value=c[top];
    top--;
    return value;
}

int priority(char c)
{
    switch(c)
    {
        case '+' : return(1);
                   break;
        case '-' : return(1);
                   break;
        case '*' : return(2);
                   break;
        case '/' : return(2);
                   break;
        case '^' : return(3);
                   break;
        default : return(0);
    }
}


int etop=-1,k,d[100];

void epush(int n)
{
    etop++;
    d[etop]=n;
}

int epop()
{
    int evalue;
    evalue=d[etop];
    etop--;
    return evalue;
}



void main()
{
   
    int i=0,j=0;
    char exp;
    printf("Enter the expression: ");
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
    if(a[i]=='(')
    {
        push(a[i]);
       
    }
    else if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
    {
        b[j]=a[i];
        j++;
    }
    else if(a[i]==')')
    {
       
        while( c[top] != '(' )
        {
            exp=pop();
            b[j]=exp;
            j++;
        }
        exp=pop();
    }
    else
    {
        if(priority(a[i])<=priority(c[top]))
        {
            b[j]=pop();
            j++;
        }
        push(a[i]);
    }
    }
    b[j]='\0';
    printf("POSTFIX NOTATION: ");
    puts(b);
	 printf("\n");
    
    for(j=0;b[j]!='\0';j++)
    {
        if ((b[j]>='a'&&b[j]<='z')||(b[j]>='A'&&b[j]<='Z'))
        {
            printf("Enter the value of %c :",b[j]);
            scanf("%d",&i);
            epush(i);
        }
        else
        {
            int x,y,R;
            y=epop();
            x=epop();
            switch(b[j])
            {
                case'+':R=x+y;
                        break;
                case'-':R=x-y;
                        break;
                case'*':R=x*y;
                        break;
                case'/':R=x/y;
                        break;
                case'^':R=x^y;
                        break;
            }
            epush(R);
        }
    }
    int ans;
    ans=epop();
	 printf("\n");
    printf("ANSWER:%d",ans);
}
