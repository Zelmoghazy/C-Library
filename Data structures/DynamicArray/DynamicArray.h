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

void InitArray(DynamicArray *DA, int initialSize);
void PrintArray(DynamicArray *DA, int start, int final);
void InsertArray(DynamicArray *DA, int value, int index);
void RemoveArray(DynamicArray *DA, int index);
int GetArray(DynamicArray *DA, int index);
int GetSize(DynamicArray *DA);
void ChangeArray(DynamicArray *DA, int value, int index);
void FreeArray(DynamicArray *DA);
void ClearArray(DynamicArray *DA, int newSize);
void CopyArray(DynamicArray *DA1, DynamicArray *DA2, int start, int end);

int BinarySearch(DynamicArray *DA, int value, bool first);
int Count(int const *A, int n, int value);

int Randomize(int start, int end);
void Swap(int *a, int *b);
void Shuffle(int *array, size_t n);
int Partition(int *A, int start, int end);
void QuickSort(DynamicArray *DA, int start, int end);
void ArrayPopulator(DynamicArray *DA, int start, int end, char choice);