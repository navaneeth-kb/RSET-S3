
#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *left,*right;
};
struct node* successor;

struct node *newnode(int key)
{
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  temp->data=key;
  temp->left=temp->right=NULL;
  return temp;
}

struct node* insert(struct node *ptr,int key)
{
  if (ptr==NULL)
  {
    return newnode(key);
  }
  else if(key<ptr->data)
  {
    ptr->left=insert(ptr->left,key);
  }
  else
  {
    ptr->right=insert(ptr->right,key);
  }
  return ptr;
}
void inorder(struct node *root)
{
  if (root!=NULL)
  {
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
  }
}
struct node *traversal(struct node *ptr)
{
  while(ptr->left!=NULL)
  {
    ptr=ptr->left;
  }
  return ptr;
}

struct node* deleteNode(struct node *root,int key)
{
  if (root==NULL)
  {
    return root;
  }
  if (key<root->data)
  {
    successor=root;
    root->left=deleteNode(root->left,key);
  }
  else if(key>root->data)
  {
    successor=root;
    root->right=deleteNode(root->right,key);
  }
  else
  {
    if (successor==root)
    {
      struct node *temp=traversal(root->right);
      temp->left=successor->left;
      return temp;
    }
    else
    {
      if (root->left==NULL)
      {
        struct node *temp=root->right;
        free(root);
        return temp;
      }
      else if (root->right==NULL)
      {
        struct node *temp=root->left;
        free(root);
        return temp;
      }
      else
      {
        struct node *temp=traversal(root->right);
        temp->left=root->left;
        root=temp;
      }
    }
   }
  return root;
}
struct node *search(struct node *root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

int main() {
    struct node *root = NULL;
    int choice, key;
      printf("\n-----------MENU---------\n");
        printf("1. INSERTION\n");
        printf("2. DELETION\n");
        printf("3. INORDER TRAVERSAL\n");
        printf("4. SEARCH NODE\n");
        printf("5. EXIT\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                struct node *result = search(root, key);
                if (result != NULL) {
                    printf("Node with key %d found in the tree.\n", key);
                } else {
                    printf("Node with key %d not found in the tree.\n", key);
                }
                break;
            case 5:exit(0);
            default:printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
