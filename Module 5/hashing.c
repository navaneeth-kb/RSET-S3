#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define EMPTY -1

int linearProbingTable[SIZE];
int quadraticProbingTable[SIZE];

int hash(int value) 
{
    return value % SIZE;
}

void insertLinearProbing( int value) 
{
    int index = hash(value);

    while (linearProbingTable[index] != EMPTY) 
    {
        index = (index + 1) % SIZE;
    }

    linearProbingTable[index] = value;
}

void insertQuadraticProbing( int value) 
{
    int index = hash(value);
    int index2=index;
    int i = 1;

    while (quadraticProbingTable[index] != EMPTY) 
    {
        index = (index2 + i * i) % SIZE;
        i++;
    }

    quadraticProbingTable[index] = value;
}
void display(int table[])
{
    for(int i=0;i<SIZE;i++)
    {
        if(table[i]!=EMPTY)
        {
            printf("%d\t",table[i]);
        }
        else
        {
            printf("empty\t");
        }
    }
}
void main()
{
    int ch,value;
    for(int i=0;i<SIZE;i++)
    {
        linearProbingTable[i]=EMPTY;
        quadraticProbingTable[i]=EMPTY;
    }
    while(1)
    {
        printf("\n1-INSERT LINEAR PROBING \n2-INSERT QUADRATIC PROBING \n3-DISPLAY LINEAR PROBING \n4-DISPLAY QUADRATIC PROBING\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter value to insert (Linear Probing): ");
                scanf("%d", &value);
                insertLinearProbing(value);
                break;
            case 2:
                printf("Enter  value to insert (Quadratic Probing): ");
                scanf("%d", &value);
                insertQuadraticProbing(value);
                break;
            case 3:
                printf("Linear Probing Table:\n");
                display(linearProbingTable);
                break;
            case 4:
                printf("Quadratic Probing Table:\n");
                display(quadraticProbingTable);
                break;
        }
    }
}
