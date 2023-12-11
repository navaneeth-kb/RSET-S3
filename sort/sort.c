#include <stdio.h>
#include <stdlib.h>

void binarysort(int a[],int max) {

   
    for (int i = 0; i < max - 1; i++) {
        for (int j = 0; j < max - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void selectionsort(int a[],int max) {

    for (int i = 0; i < max - 1; i++) {
        int min = i;
        for (int j = i + 1; j < max; j++) {
            if (a[min] > a[j]) {
                min = j;
            }
        }
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}

void insertionsort()
{
	int n,j;
	printf("Enter max value:");
	scanf("%d",&n);
	int ar[n];
	for(int i=0;i<n;i++)
	{
		printf("\nEnter element:");
		scanf("%d",&ar[i]);
		int c=ar[i];
	
		for(int l=1;l<=i;l++)
		{
			int cur=ar[l];
			j=l-1;
			while(j>=0 && ar[j]>cur)
			{	
				ar[j+1]=ar[j];
				j--;
			}
			ar[j+1]=cur; 
		}
		for(int k=0;k<=i;k++)
		{
			printf("%d \t",ar[k]);
		}
	}	
}

int main() {
    printf("Enter the max value: ");
    int n;
    scanf("%d", &n);
    int arr[n];
      printf("Enter elements of the array: ");
    for (int i = 0; i < n; i++) {
        
        scanf("%d", &arr[i]);
    }
    for (int k = 0; k < n; k++) {
        printf("%d\t", arr[k]);
    }
    printf("\n");

    int ch;
    while (1) {
        printf("\n------MENU-------\n1-Bubble Sort\n2-Selection Sort\n3-Insertion Sort\n4-Exit\nENTER CHOICE:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                binarysort(arr,n);
                for (int k = 0; k < n; k++) {
                    printf("%d\t", arr[k]);
                }
                printf("\n");
                break;
            case 2:
                selectionsort(arr,n);
                for (int k = 0; k < n; k++) {
                    printf("%d\t", arr[k]);
                }
                printf("\n");
                break;
            case 3:
                insertionsort();          
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
