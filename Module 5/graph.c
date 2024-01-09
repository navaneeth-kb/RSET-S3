#include <stdio.h>
#include <stdlib.h>

struct node {  //ajd list
    char data;
    struct node* link;
};

struct store{  //visited status and value
    char ele;
    int vis;
}p[30];

struct node *arr[30];  //ajd list
int a[30][30]={0};  //ajd matrix
int n;
char q[30];  //BFS
char stack[30];  //DFS

struct node* createNode(char data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

void adjacencyMatrix(){
    int i,j;
    printf("\nAdjacency Matrix:\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

void adjacencyList(){
    int i,j,z;
    struct node *ptr;
    printf("\ndisplaying Adjacency List\n");
    for(i=0;i<n;i++){
        ptr=arr[i];
        printf("%d. ",i);
        while(ptr!=NULL){
            printf("%c ",ptr->data);
            ptr=ptr->link;
        }
        printf("\n");
    }
}

int front=0,rear=-1;
char dequeue(){
    char x=q[front];
    front++;
    return x;
}
void enqueue(char c){
    rear++;
    q[rear]=c;
}

void BFS(){
    char s;
    int i,j;
    struct node *ptr;
    printf("enter the source: ");
    scanf(" %c",&s);
    for(i=0;i<n;i++){
        if(p[i].ele==s){
            enqueue(s);
            p[i].vis=1;
        }
    }
    printf("BFS traversal: ");
    int count=1;
    while(count!=0){
        char x=dequeue();
        printf("%c ",x);
        count--;
        for(i=0;i<n;i++){
            if(arr[i]->data==x){
                ptr=arr[i]->link;
                while(ptr!=NULL){
                    for(j=0;j<n;j++){
                        if(p[j].ele==ptr->data && p[j].vis==0){
                            enqueue(ptr->data);
                            count++;
                            p[j].vis=1;
                        }
                    }
                    ptr=ptr->link;
                }
            }
        }
    }
}


int top=0;
char pop(){
    char x=stack[top-1];
    top--;
    return x;
}
void push(char c){
    stack[top]=c;
    top++;
}

void DFS(){
    char s;
    int i,j;
    struct node *ptr;
    printf("enter the source: ");
    scanf(" %c",&s);
    for(i=0;i<n;i++){
        if(p[i].ele==s){
            push(s);
            p[i].vis=1;
        }
    }
    printf("DFS traversal: ");
    int count=1;
    while(count!=0){
        char x=pop();
        printf("%c ",x);
        count--;
        for(i=0;i<n;i++){
            if(arr[i]->data==x){
                ptr=arr[i]->link;
                while(ptr!=NULL){
                    for(j=0;j<n;j++){
                        if(p[j].ele==ptr->data && p[j].vis==0){
                            push(ptr->data);
                            count++;
                            p[j].vis=1;
                        }
                    }
                    ptr=ptr->link;
                }
            }
        }
    }
}


void main(){
    printf("enter the no of vertices:  ");
    scanf("%d",&n);
    printf("enter the vertices:  ");
    for(int i=0;i<n;i++){
        scanf(" %c",&p[i].ele);
        getchar();
        p[i].vis=0;
    }

    int i,j,z;
    struct node *ptr;
    for(i=0;i<n;i++){
        arr[i]=createNode(p[i].ele);
        ptr=arr[i];
        for(j=0;j<n;j++){
            printf("if %c is directed to %c enter 1 else 0  ",p[i].ele,p[j].ele);
            scanf("%d",&z);
            if(z==1){
                ptr->link=createNode(p[j].ele);
                ptr=ptr->link;
                a[i][j]=1;
            }
        }
    }

    while(1){
        int ch;
        printf("1.Adjacency Matrix Representation 2.Adjacency List Representation 3.BFS traversal 4.DFS traversal 5.Exit\n");
        printf("enter your choice:  ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                adjacencyMatrix();
                break;
            case 2:
                adjacencyList();
                break;
            case 3:
                BFS();
                for(int i=0;i<n;i++){
                    p[i].vis=0;
                }
                printf("\n");
                break;
            case 4:
                DFS();
                for(int i=0;i<n;i++){
                    p[i].vis=0;
                }
                printf("\n");
                break;
            default:exit(0);
        }
    }
}
