#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int Randomize(int start, int end)
{
    srand(time(NULL));
    int r = rand() % (end + 1 - start) + start;
    return r;
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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(int *array, size_t n)
{
    if (n > 1)
    {
        srand(time(NULL));
        for (size_t i = 0; i < n - 1; i++)
        {
            size_t j = rand() % (i + 1);
            swap(&array[j], &array[i]);
        }
    }
}

int Partition(int *A, int start, int end)
{
    int PivotIndex = Randomize(start, end); // random pivot : worst case is unlikely
    swap(&A[PivotIndex], &A[end]);

    int pivot = A[end];
    int partitionIndex = start;
    for (int i = start; i < end; i++)
    {
        if (A[i] <= pivot)
        {
            swap(&A[i], &A[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(&A[partitionIndex], &A[end]);
    return partitionIndex;
}

void QuickSort(int *A, int start, int end)
{
    if (start < end)
    {
        if (end <= start + 100) // insertion sort for small partitions
        {
            InsertionSort(A, start, end);
            return;
        }
        int partitionIndex = Partition(A, start, end);
        QuickSort(A, start, partitionIndex - 1);
        QuickSort(A, partitionIndex + 1, end);
    }
}

void arrayPopulator(int *A, int n, int start, int end, char choice)
{
    srand(time(NULL)); // seed is the current calendar time (seconds since Jan 1, 1970).
    for (int i = 0; i < n; i++)
    {
        if (choice == 'r')
        {
            A[i] = rand() % (end + 1 - start) + start;
        }
        else if (choice == 's')
        {
            A[i] = i;
        }
        else if (choice == 'b')
        {
            A[i] = n - i;
        }
    }
}

void printArray(int *A, int start, int end)
{
    for (int i = start; i < end; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{

    int A[100000];
    int n = sizeof(A) / sizeof(A[0]);
    arrayPopulator(A, n, 0, RAND_MAX, 's');
    shuffle(A, n);
    QuickSort(A, 0, n - 1);
    printArray(A, 0, n);
    int e = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            e++;
        }
    }
    printf("error = %d \n", e);

    system("pause");
    return 0;
}