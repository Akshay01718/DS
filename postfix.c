#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void post(char inf[100], char postf[100]);
int val(char c);
void calc(char postf[100]);
void main()
{
    char inf[100];
    char postf[100];

    printf("Enter Infix Expression : ");
    scanf("%s", inf);
    post(inf, postf);
    printf("\nPostfix expression: %s\n", postf);
    calc(postf);
}

void post(char inf[100], char postf[100])
{
    char s[100];
    int top = -1;
    int j = 0;
    int n = (int)strlen(inf);

    for (int i = 0; i < n; i++)
    {
        char c = inf[i];
        printf("Character : %c  ", c);
        printf("Stack : ");
        for (int m = 0; m < (int)strlen(postf); m++)
        {
            printf("%c ", postf[m]);
        }
        printf("\n");
        if (isalpha(c))
        {
            postf[j++] = c;
            continue;
        }
        else if (c == '(')
        {
            s[++top] = c;
            continue;
        }
        else if (c == ')')
        {
            while (top != -1 && s[top] != '(')
            {
                postf[j++] = s[top--];
                continue;
            }
            if (top != -1 && s[top] != '(')
            {
                top--;
                continue;
            }
        }
        else if (c == '^')
        {
            s[++top] = c;
            continue;
        }
        else if (c == '+' || c == '-' || c == '/' || c == '*')
        {
            while (top != -1 && val(s[top]) >= val(c))
            {
                postf[j++] = s[top--];
            }
            s[++top] = c;
        }
    }

    while (top != -1)
    {
        if (s[top] != '(')
        {
            postf[j++] = s[top--];
        }
        else
        {
            s[top--];
        }
    }
}
int val(char c)
{
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else if (c == '/' || c == '*')
    {
        return 2;
    }
    else if (c == '^')
    {
        return 3;
    }
    else
    {
        return 0;
    }
}
void calc(char postf[100])
{
    char cal[100];
    int n = (int)strlen(postf);
    int noprnd = 0;
    for (int i = 0; i < n; i++)
    {
        if (isalpha(postf[i]))
        {
            noprnd++;
        }
    }
    printf("%d", noprnd);
    int j = 0;
    int oprnd[noprnd];
    for (int i = 0; i < n; i++)
    {
        if (isalpha(postf[i]))
        {
            printf("Enter Value of %c : ", postf[i]);
            scanf("%d", &oprnd[j]);
            j++;
        }
    }
    int k = -1;
    int top = -1;
    int res[noprnd];
    for (int i = 0; i < n; i++)
    {
        if (isalpha(postf[i]))
        {
            res[++top] = oprnd[++k];
        }
        else
        {
            int a, b, r;
            a = res[top];
            b = res[top - 1];
            switch (postf[i])
            {
            case '+':
                r = b + a;
                break;
            case '-':
                r = b - a;
                break;
            case '/':
                r = b / a;
                break;
            case '*':
                r = b * a;
                break;
            case '^':
                r = pow(b, a);
                break;
            }

            res[--top] = r;
        }
    }
    printf("\n Result of the Expression is %d \n", res[0]);
}
