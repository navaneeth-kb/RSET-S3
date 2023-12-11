#include <stdio.h>
#include <stdlib.h>

int a[50],max,top;

void pushst(int value)
{
    if (top==max-1)
    {
        printf("Stack Overflow");
    }
    
    else
    {
        top++;
        a[top]=value;
    }
}

void popst()
{
    if (top==-1)
    {
        printf("Stack is Empty");
    }
    else
    {
        printf("Popped element is %d\n",a[top]);
        top--;
    }
}

void displayst()
{
    if (top==-1)
    {
        printf("Stack is Empty");
    }
    else
    {
        printf("The elements of the stack are:");
        for (int i=0;i<top+1;i++)
        {
            printf("%d\t",a[i]);
        }
        printf("\n");
    }
}

void main()
{
    int ch,n;
    top=-1;
    printf("Enter size of stack:");
    scanf("%d",&max);

    while (1)
    {
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT");
        printf("\nEnter choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter value to be pushed:");
                scanf("%d",&n);
                pushst(n);
                break;

            case 2:
                popst();
                break;

            case 3:
                displayst();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("INVALID CHOICE!!!");
                break;
        }
    }
}
