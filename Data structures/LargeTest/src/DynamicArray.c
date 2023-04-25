#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdarg.h>
#include <stdint.h>

typedef struct DynamicArray
{
    int64_t end;
    int64_t MAX;
    int64_t *A;
} DynamicArray;

void InsertArray(DynamicArray *DA, int64_t value, int64_t index);
void RemoveArray(DynamicArray *DA, int64_t index);

void delay(int64_t ms) // delay function
{
    clock_t timeDelay = ms + clock();
    while (timeDelay > clock())
        ;
}

void LogColor(char *text, char c)
{
    switch (c)
    {
    case 'r':
    {
        printf("\033[1;31m");
    }
    break;
    case 'y':
    {
        printf("\033[1;33m");
    }
    break;
    case 'b':
    {
        printf("\033[0;34m");
    }
    break;
    case 'p':
    {
        printf("\033[0;35m");
    }
    break;
    case 'g':
    {
        printf("\033[0;32m");
    }
    break;
    default:
    {
        printf("\033[0m");
    }
    break;
    }
    printf("%s\n", text);
    printf("\033[0m");
}

void Swap(int64_t *a, int64_t *b)
{
    int64_t temp = *a;
    *a = *b;
    *b = temp;
}

int64_t Randomize(int64_t start, int64_t end)
{
    if (end + 1 - start != 0)
    {
        srand(time(NULL));
        int64_t r = rand() % (end + 1 - start) + start;
        return r;
    }
    else
    {
        LogColor("Randomize failed : set a valid range", 'r');
        return -1;
    }
}

void Shuffle(int64_t *A, int64_t n)
{
    if (n > 1)
    {
        srand(time(NULL));
        for (int64_t i = 0; i < n - 1; i++)
        {
            int64_t j = rand() % (i + 1);
            Swap(&A[j], &A[i]);
        }
    }
}

DynamicArray *newArray(int64_t initialSize)
{
    DynamicArray *DA = (DynamicArray *)malloc(sizeof(DynamicArray));
    DA->MAX = initialSize;
    DA->end = 0;
    DA->A = calloc(DA->MAX, sizeof(int64_t));
    if (DA->A == NULL)
    {
        LogColor("Allocation failed", 'r');
        delay(5000);
        exit(0);
    }
    return DA;
}

void FreeArray(DynamicArray *DA)
{
    free(DA->A);
    DA->A = NULL;
    free(DA);
}

bool isEmpty(DynamicArray *DA)
{
    if (DA->end == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void PrintArray(DynamicArray *DA, int64_t start, int64_t final)
{
    if (final > DA->MAX)
    {
        LogColor("Print Array failed : Exceeded max size", 'r');
        return;
    }
    LogColor("-------------------------", 'p');
    for (int64_t j = start; j < final; j++)
    {
        printf("%lld ", DA->A[j]);
    }
    printf("\n");
    if (isEmpty(DA))
    {
        LogColor("Empty Array !", 'y');
    }
    printf("\033[0;32m"); // green color
    printf("Last used Index: %lld\n", DA->end);
    printf("Array Capacity: %lld\n", DA->MAX);
    printf("\033[0m"); /// reset white color
    LogColor("-------------------------", 'p');
}

void Expand(DynamicArray *DA)
{
    // When it exceeds the capacity of array
    DA->MAX = DA->MAX * 2;
    int64_t *B = realloc(DA->A, DA->MAX * sizeof(int64_t));
    if (B == NULL)
    {
        // check if reallocation succeeded
        LogColor("Reallocation failed", 'r');
        delay(5000);
        exit(0);
    }
    for (int64_t i = DA->MAX / 2; i < DA->MAX; i++)
    {
        // realloc produce garbage values
        // reinitialized by 0
        B[i] = 0;
    }

    DA->A = B;
}

void Shrink(DynamicArray *DA)
{
    DA->MAX = DA->MAX / 2;
    int64_t *B = realloc(DA->A, DA->MAX * sizeof(int64_t));
    if (B == NULL)
    {
        // check if reallocation succeeded
        LogColor("Reallocation failed", 'r');
        delay(5000);
        exit(0);
    }
    DA->A = B;
}

void Append(DynamicArray *DA, int64_t value)
{
    if (DA->end < DA->MAX)
    {
        DA->A[DA->end] = value;
        DA->end++;
    }
    else
    {
        InsertArray(DA, value, DA->end);
    }
}

void Pop(DynamicArray *DA)
{
    if (DA->end < DA->MAX / 4)
    {
        RemoveArray(DA, DA->end);
    }
    else
    {
        DA->end--;
        DA->A[DA->end] = 0;
    }
}

void InsertArray(DynamicArray *DA, int64_t value, int64_t index)
{
    if (index >= 0)
    {
        if (index >= DA->MAX || DA->end >= DA->MAX)
        {
            Expand(DA);
            InsertArray(DA, value, index);
        }

        // Append the array
        else if (index == DA->end)
        {
            Append(DA, value);
        }
        // Insert at any position
        else
        {
            for (int64_t j = DA->end; j > index; j--)
            {
                DA->A[j] = DA->A[j - 1];
            }
            DA->A[index] = value;
            DA->end++;
        }
    }
    else
    {
        LogColor("Insert Array failed: index must be positive value", 'r');
        return;
    }
}

void RemoveArray(DynamicArray *DA, int64_t index)
{
    if (index <= DA->end && index >= 0 && DA->end > 0)
    {
        if (DA->end < DA->MAX / 4) // shrink to half when it falls below quarter of max size
        {
            Shrink(DA);
            RemoveArray(DA, index);
        }
        else if (index == DA->end)
        {
            Pop(DA);
        }
        else
        {
            for (int64_t j = index; j < DA->end - 1; j++)
            {
                DA->A[j] = DA->A[j + 1];
            }
            DA->end--;
            DA->A[DA->end] = 0;
        }
    }
    else
    {
        printf("\033[1;31m");
        printf("RemoveArray failed: cannot remove unintialized data,max index = %lld \n", DA->end);
        printf("\033[0m");
        return;
    }
}

void RemoveArrayValue(DynamicArray *DA, int64_t value)
{
    int64_t count = 0;
    for (int64_t i = 0; i < DA->end; i++)
    {
        if (DA->A[i] == value)
        {
            RemoveArray(DA, i);
            i--;
            count++;
        }
    }
    if (count == 0)
    {
        LogColor("RemoveArrayValue failed: The value couldnt be found", 'r');
    }
}

void RemoveArrayRange(DynamicArray *DA, int64_t start, int64_t end)
{
    if (start >= 0 && start < end && end <= DA->end)
    {
        for (int64_t i = start; i <= end; i++)
        {
            RemoveArray(DA, start);
        }
    }
    else
    {
        LogColor("RemoveArrayRange failed: invalid range", 'r');
    }
}

int64_t GetArray(DynamicArray *DA, int64_t index)
{
    if (index > DA->end || index < 0)
    {
        LogColor("GetArray failed: Cannot access uninitialized data", 'r');
        return 0;
    }
    return DA->A[index];
}

int64_t GetSize(DynamicArray *DA)
{
    return DA->MAX;
}

void ChangeArray(DynamicArray *DA, int64_t value, int64_t index)
{
    if (index > DA->end || index < 0)
    {
        printf("\033[1;31m");
        printf("Change Array failed: Cannot change not yet initialized data, Max index = %lld \n", DA->end);
        printf("\033[0m");
        return;
    }
    DA->A[index] = value;
}

void ClearArray(DynamicArray *DA, int64_t newSize)
{
    if (DA->MAX > newSize)
    {
        DA->end = newSize;

        while (DA->MAX >= newSize * 2)
        {
            Shrink(DA);
        }
        for (int64_t i = 0; i < DA->MAX; i++)
        {
            DA->A[i] = 0;
        }
    }
    else
    {
        for (int64_t i = 0; i <= DA->end; i++)
        {
            DA->A[i] = 0;
        }
    }
}

void CopyArray(DynamicArray *DA1, DynamicArray *DA2, int64_t start, int64_t end)
{
    // copy from array2 from cerain range -> array1
    if (DA2->end >= end)
    {
        int64_t j = 0;
        for (int64_t i = start; i < end; i++)
        {
            DA1->A[j] = DA2->A[i];
            j++;
        }
        DA1->end = j;
    }
    else
    {
        LogColor("CopyArray failed: Cannot copy uninitialized data", 'r');
    }
}

void ReverseArray(DynamicArray *DA)
{
    int64_t i = 0;
    int64_t j = DA->end - 1;
    while (j > i)
    {
        Swap(&DA->A[i++], &DA->A[j--]);
    }
}

int64_t BinarySearch(DynamicArray *DA, int64_t value, bool first)
{
    int64_t start = 0;
    int64_t end = DA->end - 1;
    int64_t result = -1;

    while (start <= end)
    {
        int64_t mid = (start + end) / 2;
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

int64_t Count(DynamicArray *DA, int64_t value)
{
    int64_t firstIndex = BinarySearch(DA, value, true);
    int64_t lastIndex = BinarySearch(DA, value, false);
    return lastIndex - firstIndex + 1;
}

void InsertionSort(int64_t *a, int64_t start, int64_t end)
{
    for (int64_t i = start + 1; i < end + 1; i++)
    {
        int64_t value = a[i];
        int64_t next = i;
        while (next > 0 && a[next - 1] > value)
        {
            a[next] = a[next - 1];
            next = next - 1;
        }
        a[next] = value;
    }
}

int64_t MedianOfThree(int64_t *A, int64_t left, int64_t right)
{
    int64_t center = left + (right - left) / 2;
    if (A[center] < A[left])
    {
        Swap(&A[left], &A[center]);
    }
    if (A[right] < A[left])
    {
        Swap(&A[left], &A[right]);
    }
    if (A[right] < A[center])
    {
        Swap(&A[center], &A[right]);
    }
    return center;
}

int64_t Partition(int64_t *A, int64_t start, int64_t end)
{
    int64_t PivotIndex = Randomize(start, end);
    // int64_t PivotIndex = MedianOfThree(A, start, end);
    Swap(&A[PivotIndex], &A[start]);
    int64_t i = start;
    int64_t partitionIndex = end + 1;
    int64_t pivot = A[start];

    while (1)
    {
        while (A[++i] < pivot)
        {
            if (i == end)
            {
                break;
            }
        }
        while (A[--partitionIndex] > pivot)
        {
            if (partitionIndex == start)
            {
                break;
            }
        }
        if (i >= partitionIndex)
        {
            break;
        }
        Swap(&A[i], &A[partitionIndex]);
    }
    Swap(&A[start], &A[partitionIndex]);
    return partitionIndex;
}

void QuickSort(DynamicArray *DA, int64_t start, int64_t end)
{
    if (start < end)
    {
        if (end - start < 2)
        {
            return;
        } // partition with two values
        else if (end - start == 2)
        {
            if (DA->A[start] > DA->A[end - 1])
            {
                Swap(&DA->A[start], &DA->A[end - 1]);
            }
            return;
        }
        // to deal with repitition
        for (int64_t i = start; i < end; i++)
        {
            if (DA->A[i + 1] != DA->A[i])
            {
                break;
            }
            else if (i == end - 1)
            {
                return;
            }
        }
        if (end <= start + 30) // insertion sort for small partitions
        {
            InsertionSort(DA->A, start, end);
            return;
        }
        int64_t partitionIndex = Partition(DA->A, start, end);
        QuickSort(DA, start, partitionIndex - 1);
        QuickSort(DA, partitionIndex + 1, end);
    }
}

void ArrayPopulator(DynamicArray *DA, ...)
{
    va_list args;
    va_start(args, DA);
    unsigned char choice = (unsigned char)va_arg(args, int64_t);
    int64_t start = va_arg(args, int64_t);
    int64_t end = va_arg(args, int64_t);
    srand(time(NULL)); // seed is the current calendar time (seconds since Jan 1, 1970).
    for (int64_t i = 0; i < DA->MAX; i++)
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
            DA->A[i] = DA->MAX - i - 1;
            DA->end++;
        }
        else if (choice == 'c')
        {
            DA->A[i] = start;
            DA->end++;
        }
        else if (choice == 'v')
        {
            if (i % 2 == 0)
                DA->A[i] = start;
            else
                DA->A[i] = end;
            DA->end++;
        }
        else if (choice == 'f')
        {
            if (i <= 1)
            {
                DA->A[i] = i;
            }
            else
            {
                DA->A[i] = (int64_t)DA->A[i - 1] + (int64_t)DA->A[i - 2];
            }
            DA->end++;
        }
        else
        {
            choice = 's';
            i--;
        }
    }
    va_end(args);
}

int64_t Power(int64_t x, int64_t n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return Power(x * x, n / 2);
    }
    else
    {
        return Power(x * x, n / 2) * x;
    }
}

void Exponentiate(DynamicArray *DA, int64_t pow)
{
    for (int64_t i = 0; i < DA->end; i++)
    {
        DA->A[i] = Power((int64_t)DA->A[i], pow);
    }
}

int64_t Maximum(DynamicArray *DA)
{
    int64_t MAX = -INT_MAX;
    for (int64_t i = 0; i < DA->end; i++)
    {
        if (DA->A[i] > MAX)
        {
            MAX = DA->A[i];
        }
    }
    return MAX;
}
int64_t Minimum(DynamicArray *DA)
{
    int64_t MIN = INT_MAX;
    for (int64_t i = 0; i < DA->end; i++)
    {
        if (DA->A[i] < MIN)
        {
            MIN = DA->A[i];
        }
    }
    return MIN;
}