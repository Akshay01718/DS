#include <stdio.h>
#include <stdlib.h>

struct tree
{
    char data;
    struct tree *lchild;
    struct tree *rchild;
};

struct tree *newNode(char data)
{
    struct tree *node = (struct tree *)malloc(sizeof(newNode));
    node->lchild = NULL;
    node->rchild = NULL;
    node->data = data;
    return node;
}

struct tree *nullNode()
{
    struct tree *nullNode = (struct tree *)malloc(sizeof(struct tree));
    nullNode->lchild = NULL;
    nullNode->rchild = NULL;
    nullNode->data = '\0';
    return nullNode;
}

struct tree *ptr = NULL;

void inorder(struct tree *ptr)
{
    if (ptr != NULL)
    {
        inorder(ptr->lchild);
        printf("%c", ptr->data);
        inorder(ptr->rchild);
    }
}

void preorder(struct tree *ptr)
{
    if (ptr != NULL)
    {
        printf("%c", ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}

void postorder(struct tree *ptr)
{
    if (ptr != NULL)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%c", ptr->data);
    }
}

void insertTree(struct tree *ptr)
{
    char dat[2];
    int choice;
    printf("Enter Data : ");
    scanf("%s", dat);
    ptr->data = (char)dat[0];
    printf("Does %c have a Left Child?(1/0) : ", ptr->data);
    scanf("%d", &choice);
    if (choice == 1)
    {
        ptr->lchild = nullNode();
        insertTree(ptr->lchild);
    }

    printf("Does %c have a Right Child?(1/0) : ", ptr->data);
    scanf("%d", &choice);
    if (choice == 1)
    {
        ptr->rchild = nullNode();
        insertTree(ptr->rchild);
    }
}

int main()
{
    int g;
    struct tree *root = nullNode();
    printf("Enter the Expression:\n");
    insertTree(root);
    while (1)
    {
        printf("\n");
        printf("\n1.InOrder\n2.PreOrder\n3.PostOrder\n4.Exit\n");
        printf("Enter your Choice : ");
        scanf("%d", &g);
        switch (g)
        {
        case 1:
            inorder(root);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            postorder(root);
            break;
        case 4:
            exit(0);
            break;
        }
    }
    return 0;
}