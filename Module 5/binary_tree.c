#include <stdio.h>
#include <stdlib.h>

int arr[100] = {-1};
int count = 0;

void inorder(int i) {
    if (i <= count) {
        inorder(2 * i);
        printf("%d ", arr[i]);
        inorder(2 * i + 1);
    }
}

void preorder(int i) {
    if (i <= count) {
        printf("%d ", arr[i]);
        preorder(2 * i);
        preorder(2 * i + 1);
    }
}

void postorder(int i) {
    if (i <= count) {
        postorder(2 * i);
        postorder(2 * i + 1);
        printf("%d ", arr[i]);
    }
}

void insert(int value) {
    count++;
    arr[count] = value;
}

void delete(int value) {
    int i;
    while (arr[i] != value && i <= count) {
        i++;
    }
    if (i <= count) {
        arr[i] = arr[count];
        arr[count] = -1;
        count--;
    } else {
        printf("Value not found in the tree.\n");
    }
}

int search(int value, int i) {
    if (i <= count) {
        if (arr[i] == value) {
            return 1; // Value found
        } else if (value < arr[i]) {
            return search(value, 2 * i); // Search in left subtree
        } else {
            return search(value, 2 * i + 1); // Search in right subtree
        }
    }
    return 0; // Value not found
}

void main() {
    int ch, val;

    while (1) {
        printf("\n1-INSERT \n2-DELETE \n3-INORDER TRAVERSAL \n4-PREORDER TRAVERSAL \n5-POSTORDER TRAVERSAL\n6-SEARCH\n7-EXIT\n");
        printf("Enter choice:");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value:");
                scanf("%d", &val);
                insert(val);
                break;
            case 2:
                printf("Enter value:");
                scanf("%d", &val);
                delete(val);
                break;
            case 3:
                inorder(1);
                break;
            case 4:
                preorder(1);
                break;
            case 5:
                postorder(1);
                break;
            case 6:
                printf("Enter value to search:");
                scanf("%d", &val);
                if (search(val, 1)) {
                    printf("Value found in the tree.\n");
                } else {
                    printf("Value not found in the tree.\n");
                }
                break;
            case 7:
                exit(0);
        }
    }
}
