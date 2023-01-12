#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack
{
    int top;
    int MAX;
    int *A;
} Stack;

void InitStack(Stack *S, int initialSize)
{
    S->MAX = initialSize;
    S->top = 0;
    S->A = calloc(S->MAX, sizeof(int));
    if (S->A == NULL)
    {
        printf("Allocation failed");
        exit(0);
    }
}

void PrintStack(Stack *S)
{
    printf("-------------------------\n");
    for (int j = 0; j < S->top; j++)
    {
        printf("%d ", S->A[j]);
    }
    printf("\n");
    printf("Stack Top Index: %d\n", S->top);
    printf("Stack Capacity: %d\n", S->MAX);
    printf("-------------------------\n");
}

void FreeStack(Stack *S)
{
    free(S->A);
    S->A = NULL;
}

void Push(Stack *S, int value)
{
    if (S->top < S->MAX)
    {
        S->A[S->top] = value;
        S->top++;
    }
    else
    {
        printf("Stack overflow");
    }
}

void Pop(Stack *S)
{
    if (S->top == 0)
    {
        printf("Empty Stack");
    }
    else
    {
        S->top--;
        S->A[S->top] = 0;
    }
}

bool IsStackEmpty(Stack *S)
{
    if (S->top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int stackTop(Stack *S)
{
    if (S->top > 0)
    {
        return S->A[S->top - 1];
    }
    else
    {
        printf("Empty Stack");
        return -1;
    }
}

void stackPop(Stack *S)
{
    if (S->top > 0)
    {
        S->top--;
    }
    else
    {
        printf("Empty Stack");
    }
}

bool isEqual(Stack S1, Stack S2)
{
    while (!IsStackEmpty(S1) && !IsStackEmpty(S2))
    {
        if (stackTop(S1) != stackTop(S2))
        {
            return false;
        }
        stackPop(&S1);
        stackPop(&S2);
    }
    return (IsStackEmpty(S1) && IsStackEmpty(S2));
}

void StackRemoveRepeated(Stack *S)
{
    Stack unique;
    InitArray(&unique, S->top);
    for (int i = 0; i < S->top; i++)
    {
        if (i == 0 || stackTop(unique) != S->A[i])
        {
            // push first element to stack
            // if top not repeated element push to unique
            Append(&unique, (int)(S->A[i]));
        }
    }
    FreeArray(S);
    *S = unique;
}