#include <stdio.h>
#include <stdlib.h>

typedef struct DynamicArray
{
    int end;
    int MAX;
    int *A;
} DynamicArray;

void initArray(DynamicArray *DA, int size)
{
    DA->MAX = size;
    DA->end = 0;
    DA->A = calloc(DA->MAX, sizeof(int));
    if (DA->A == NULL)
    {
        printf("Allocation failed");
        exit(0);
    }
}

void printArray(DynamicArray *DA, int start, int final)
{
    for (int j = start; j < final; j++)
    {
        printf("%d ", DA->A[j]);
    }
    printf("\n");
}

void insertArray(DynamicArray *DA, int value, int index)
{
    if (index >= 0)
    {
        // pass address of pointer to be able to alter it
        if (index >= DA->MAX || DA->end >= DA->MAX)
        {
            DA->MAX = DA->MAX * 2;
            int *B = realloc(DA->A, (DA->MAX + 1) * sizeof(int));

            for (int i = DA->MAX / 2; i < DA->MAX + 1; i++)
            {
                // realloc produce garbage values
                B[i] = 0;
            }
            if (B == NULL)
            {
                // check if reallocation succeeded
                printf("Reallocation failed");
                exit(0);
            }

            DA->A = B;

            insertArray(DA, value, index);
        }
        else if (index == DA->end)
        {
            DA->A[DA->end] = value;
            DA->end++;
        }
        else
        {
            for (int j = DA->end + 1; j > index; j--)
            {
                DA->A[j] = DA->A[j - 1];
            }
            DA->A[index] = value;
            DA->end++;
        }
    }
    else
    {
        printf("Insert Array :index must be positive value\n");
        return;
    }
}

void removeArray(DynamicArray *DA, int index)
{
    if (index <= DA->end && index >= 0)
    {
        if (DA->end < DA->MAX / 2)
        {
            DA->MAX = DA->MAX / 2;
            int *B = realloc(DA->A, DA->MAX * sizeof(int));
            if (B == NULL)
            {
                // check if reallocation succeeded
                printf("Reallocation failed");
                exit(0);
            }
            DA->A = B;
            removeArray(DA, index);
        }
        else if (index == DA->end)
        {
            DA->end--;
            DA->A[DA->end] = 0;
        }
        else
        {
            for (int j = index; j < DA->end + 1; j++)
            {
                DA->A[j] = DA->A[j + 1];
            }
            DA->A[DA->end] = 0;
            DA->end--;
        }
    }
    else
    {
        printf("RemoveArray failed: cannot remove unintialized data, max index = %d \n", DA->end);
        return;
    }
}

int GetArray(DynamicArray *DA, int index)
{
    if (index < 0)
    {
    }
    return DA->A[index];
}

int getSize(DynamicArray *DA)
{
    return DA->MAX;
}

void ChangeArray(DynamicArray *DA, int value, int index)
{
    if (index > DA->end || index < 0)
    {
        printf("Change Array : cannot change not yet initialized data,max index = %d \n", DA->end);
        return;
    }
    DA->A[index] = value;
}

void freeArray(DynamicArray *DA)
{
    free(DA->A);
}

void ClearArray(DynamicArray *DA, int size)
{

    if (DA->MAX > size)
    {
        DA->end = size;

        while (DA->MAX >= size * 2)
        {
            DA->MAX = DA->MAX / 2;
            int *B = realloc(DA->A, DA->MAX * sizeof(int));
            if (B == NULL)
            {
                // check if reallocation succeeded
                printf("Reallocation failed");
                exit(0);
            }
            DA->A = B;
        }
        for (int i = 0; i < DA->MAX; i++)
        {
            DA->A[i] = 0;
        }
    }
    else
    {
        for (int i = 0; i <= DA->end; i++)
        {
            DA->A[i] = 0;
        }
    }
}

int main()
{
    DynamicArray a1;

    initArray(&a1, 100);

    for (int i = 0; i < 110; i++)
    {
        insertArray(&a1, i, a1.end);
    }

    printArray(&a1, 0, a1.end);
    printf("%d\n", a1.end);
    printf("%d\n", a1.MAX);

    printf("/*******************************************/ \n");

    ClearArray(&a1, 200);

    printArray(&a1, 0, a1.MAX);
    printf("%d\n", a1.end);
    printf("%d\n", a1.MAX);

    freeArray(&a1);

    system("pause");
    return 0;
}