#include <stdio.h>
#include <stdlib.h>

struct node
{
    int co, expo;
    struct node *link;
};

struct node *p1, *p2, *pr;

struct node *readpoly()
{
    struct node *new, *ptr, *head = NULL;
    int n, i;

    printf("Enter Total Number of Terms in Polynomial : ");
    scanf("%d", &n);

    printf("Enter the Coefficient and Exponent of Each Term\n");
    for (i = 0; i < n; i++)
    {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the Coefficient of Term %d : ", i + 1);
        scanf("%d", &new->co);
        printf("Enter the Exponent of Term %d : ", i + 1);
        scanf("%d", &new->expo);
        new->link = NULL;
        if (head == NULL)
        {
            head = new;
            ptr = head;
        }
        else
        {
            ptr->link = new;
            ptr = new;
        }
    }
    return head;
}

struct node *multiply(struct node *p1, struct node *p2)
{
    struct node *p, *q, *last = NULL, *r = NULL, *temp, *head = NULL;

    for (p = p1; p != NULL; p = p->link)
    {
        for (q = p2; q != NULL; q = q->link)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->co = p->co * q->co;
            temp->expo = p->expo + q->expo;
            temp->link = NULL;

            if (head == NULL)
            {
                head = temp;
                last = temp;
            }
            else
            {
                r = head;
                struct node *prev = NULL;
                while (r != NULL && r->expo >= temp->expo)
                {
                    if (r->expo == temp->expo)
                    {
                        r->co = r->co + temp->co;
                        break;
                    }
                    prev = r;
                    r = r->link;
                }
                if (r == NULL)
                {
                    last->link = temp;
                    last = temp;
                }
                else if (r->expo != temp->expo)
                {
                    temp->link = r;
                    if (prev == NULL)
                    {
                        head = temp;
                    }
                    else
                    {
                        prev->link = temp;
                    }
                }
            }
        }
    }
    return head;
}

void display(struct node *head)
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("Polynomial is Empty\n");
    }
    else
    {
        ptr = head;
        while (ptr->link != NULL)
        {
            if (ptr->co != 0)
            {
                if (ptr->expo != 0)
                {
                    printf("%dx^%d + ", ptr->co, ptr->expo);
                }
                else
                {
                    printf("%d + ", ptr->co);
                }
            }
            ptr = ptr->link;
        }
        if (ptr->co != 0)
        {
            if (ptr->expo != 0)
            {
                printf("%dx^%d", ptr->co, ptr->expo);
            }
            else
            {
                printf("%d", ptr->co);
            }
        }
    }
    printf("\n");
}

void main()
{
    printf("Enter the First Polynomial : \n");
    p1 = readpoly();
    printf("Enter the Second Polynomial : \n");
    p2 = readpoly();
    printf("First Polynomial is : ");
    display(p1);
    printf("Second Polynomial is : ");
    display(p2);
    pr = multiply(p1, p2);
    printf("Multiplied Polynomial is : ");
    display(pr);
}