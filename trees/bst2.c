
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node *insertNode(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }

    return root;
}
void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
void preorderTraversal(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}
void postorderTraversal(struct Node *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}
struct Node *searchNode(struct Node *root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return searchNode(root->left, value);
    }

    return searchNode(root->right, value);
}
struct Node *minValueNode(struct Node *node) {
    struct Node *current = node;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}
struct Node *deleteNode(struct Node *root, int value) {
    if (root == NULL) {
        printf("Element not present in the BST.\n");
        return root;
    }
    
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else 
{
  
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void displayMenu() {
    printf("\n--------Binary Search Tree-------\n");
    printf("1. INSERTION\n");
    printf("2. DELETION\n");
    printf("3. INORDER TRAVERSAL\n");
    printf("4. PREORDER TRAVERSAL\n");
    printf("5. POSTORDER TRAVERSAL\n");
    printf("6. SEARCH\n");
    printf("7. EXIT\n");
}

int main() {
    struct Node *root = NULL;
    int choice, value;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                inorderTraversal(root);
                printf("\n");
                break;
            case 4:
                preorderTraversal(root);
                printf("\n");
                break;
            case 5:
                postorderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                if (searchNode(root, value) != NULL) {
                    printf("Node found in the BST.\n");
                } else {
                    printf("Node not found in the BST.\n");
                }
                break;
            case 7:
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 7);

    return 0;
}
	

