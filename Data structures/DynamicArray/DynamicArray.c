#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct DynamicArray
{
    int end;
    int MAX;
    int *A;
} DynamicArray;

void InitArray(DynamicArray *DA, int initialSize)
{
    DA->MAX = initialSize;
    DA->end = 0;
    DA->A = calloc(DA->MAX, sizeof(int));
    if (DA->A == NULL)
    {
        printf("Allocation failed");
        exit(0);
    }
}

void PrintArray(DynamicArray *DA, int start, int final)
{
    printf("-------------------------\n");
    for (int j = start; j < final; j++)
    {
        printf("%d ", DA->A[j]);
    }
    printf("\n");
    printf("Last used Index: %d\n", DA->end);
    printf("Array Max Index: %d\n", DA->MAX);
    printf("-------------------------\n");
}

void InsertArray(DynamicArray *DA, int value, int index)
{
    if (index >= 0)
    {
        // Pass address of pointer to be able to alter it
        if (index >= DA->MAX || DA->end >= DA->MAX)
        {
            // When it exceeds the capacity of array
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

            InsertArray(DA, value, index);
        }
        // Append the array
        else if (index == DA->end)
        {
            DA->A[DA->end] = value;
            DA->end++;
        }
        // Insert at any position
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
        printf("Insert Array failed: index must be positive value\n");
        return;
    }
}

void RemoveArray(DynamicArray *DA, int index)
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
            RemoveArray(DA, index);
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
    if (index > DA->end)
    {
        printf("GetArray failed: Cannot access uninitialized data \n");
        return 0;
    }
    return DA->A[index];
}

int GetSize(DynamicArray *DA)
{
    return DA->MAX;
}

void ChangeArray(DynamicArray *DA, int value, int index)
{
    if (index > DA->end || index < 0)
    {
        printf("Change Array failed: Cannot change not yet initialized data, Max index = %d \n", DA->end);
        return;
    }
    DA->A[index] = value;
}

void FreeArray(DynamicArray *DA)
{
    free(DA->A);
    DA->A = NULL;
}

void ClearArray(DynamicArray *DA, int newSize)
{

    if (DA->MAX > newSize)
    {
        DA->end = newSize;

        while (DA->MAX >= newSize * 2)
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

void CopyArray(DynamicArray *DA1, DynamicArray *DA2, int start, int end)
{
    // copy from array2 from cerain range -> array1
    if (DA2->end >= end)
    {
        int j = 0;
        for (int i = start; i < end; i++)
        {
            DA1->A[j] = DA2->A[i];
            j++;
        }
        DA1->end = j;
    }
    else
    {
        printf("CopyArray failed: Cannot copy uninitialized data \n");
    }
}

int BinarySearch(DynamicArray *DA, int value, bool first)
{
    int start = 0;
    int end = DA->end - 1;
    int result = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (DA->A[mid] == value)
        {
            result = mid;
            if (first)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else if (value < DA->A[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return result;
}

int Count(DynamicArray *DA, int n, int value)
{
    int firstIndex = BinarySearch(DA, value, true);
    int lastIndex = BinarySearch(DA, value, false);
    return lastIndex - firstIndex + 1;
}

int Randomize(int start, int end)
{
    if (end + 1 - start != 0)
    {
        srand(time(NULL));
        int r = rand() % (end + 1 - start) + start;
        return r;
    }
    else
    {
        printf("Randomize failed : set a valid range");
        return -1;
    }
}

void InsertionSort(int *a, int start, int end)
{
    int value, next;
    for (int i = start + 1; i < end + 1; i++)
    {
        value = a[i];
        next = i;
        while (next > 0 && a[next - 1] > value)
        {
            a[next] = a[next - 1];
            next = next - 1;
        }
        a[next] = value;
    }
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Shuffle(int *array, size_t n)
{
    if (n > 1)
    {
        srand(time(NULL));
        for (size_t i = 0; i < n - 1; i++)
        {
            size_t j = rand() % (i + 1);
            Swap(&array[j], &array[i]);
        }
    }
}

int Partition(int *A, int start, int end)
{
    // random pivot : worst case is unlikely
    int PivotIndex = Randomize(start, end);
    Swap(&A[PivotIndex], &A[end]);

    int pivot = A[end];
    int partitionIndex = start;
    for (int i = start; i < end; i++)
    {
        if (A[i] <= pivot)
        {
            Swap(&A[i], &A[partitionIndex]);
            partitionIndex++;
        }
    }
    Swap(&A[partitionIndex], &A[end]);
    return partitionIndex;
}

void QuickSort(DynamicArray *DA, int start, int end)
{
    Shuffle(DA->A, DA->end);
    if (start < end - 1)
    {
        if (end - 1 <= start + 100) // insertion sort for small partitions
        {
            InsertionSort(DA->A, start, end - 1);
            return;
        }
        int partitionIndex = Partition(DA->A, start, end - 1);
        QuickSort(DA, start, partitionIndex - 1);
        QuickSort(DA, partitionIndex + 1, end - 1);
    }
}

void ArrayPopulator(DynamicArray *DA, int start, int end, char choice)
{
    srand(time(NULL)); // seed is the current calendar time (seconds since Jan 1, 1970).
    for (int i = 0; i < DA->MAX; i++)
    {
        if (choice == 'r')
        {
            DA->A[i] = rand() % (end + 1 - start) + start;
            DA->end++;
        }
        else if (choice == 's')
        {
            DA->A[i] = i;
            DA->end++;
        }
        else if (choice == 'b')
        {
            DA->A[i] = DA->MAX - i;
            DA->end++;
        }
    }
}
