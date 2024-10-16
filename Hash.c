#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node
{
    int data;
    struct Node *next;
};

struct Node *hashT[SIZE];

void inhashT()
{
    for (int i = 0; i < SIZE; i++)
    {
        hashT[i] = NULL;
    }
}

int hashfunc(int key)
{
    return key % SIZE;
}

void insert(int key)
{
    int index = hashfunc(key);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;

    if (hashT[index] == NULL)
    {
        hashT[index] = newNode;
    }
    else
    {
        struct Node *temp = hashT[index];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void disphashT()
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("Index %d:", i);
        if (hashT[i] == NULL)
        {
            printf(" ----\n");
        }
        else
        {
            struct Node *temp = hashT[i];
            while (temp != NULL)
            {
                printf("%d -->", temp->data);
                temp = temp->next;
            }
            printf(" NULL\n");
        }
    }
}

int main()
{
    inhashT();
    int choice, key;

    do
    {
        printf("\nMenu:\n");
        printf("1.Insert an Element\n2.Display Hash Table\n3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the Element to Insert: ");
            scanf("%d", &key);
            insert(key);
            break;
        case 2:
            printf("\nHash Table : \n");
            disphashT();
            break;
        case 3:
            break;
        default:
            printf("Invalid choice!\n");
            break;
        }
    } while (choice != 3);

    return 0;
}
