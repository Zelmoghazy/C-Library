#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct StaticArray
{
    int end;
    int A[MAX];
} StaticArray;

void InitArray(StaticArray *A)
{
    A->end = 0;
    for (int i = 0; i < MAX; i++)
    {
        A->A[i] = 0;
    }
}

int get(StaticArray *A, int index)
{
    return A->A[index];
}

int getSize(StaticArray *A)
{
    return A->end;
}

void printArray(StaticArray *A, int start, int final)
{
    for (int j = start; j < final; j++)
    {
        printf("%d ", A->A[j]);
    }
    printf("\n");
}

void insertArray(StaticArray *A, int e, int n)
{
    if (n != A->end)
    {
        if (n >= MAX || A->end >= MAX)
        {
            printf("Exceeded Array Size");
            return;
        }
        for (int j = A->end; j > n; j--)
        {
            A->A[j] = A->A[j - 1];
        }
        A->A[n] = e;
        A->end++;
    }
    else
    {
        A->A[A->end] = e;
        A->end++;
    }
}

void removeArray(StaticArray *A, int n)
{
    if (n != A->end)
    {
        if (n > MAX)
        {
            printf("Exceeded Array Size");
            return;
        }
        if (n > A->end)
        {
            printf("No elements to remove");
            return;
        }
        for (int j = n; j < A->end - 1; j++)
        {
            A->A[j] = A->A[j + 1];
        }
        A->end--;
        A->A[A->end] = 0;
    }
    else
    {
        A->end--;
        A->A[A->end] = 0;
    }
}

int main()
{
    StaticArray a1;
    InitArray(&a1);
    insertArray(&a1, 1, 0);
    insertArray(&a1, 2, 1);
    insertArray(&a1, 3, 2);
    insertArray(&a1, 4, 3);
    insertArray(&a1, 4, 3);
    printf("%d\n", getSize(&a1));
    printArray(&a1, 0, a1.end);
    removeArray(&a1, 1);
    printArray(&a1, 0, a1.end+1);
    system("pause");
    return 0;
}