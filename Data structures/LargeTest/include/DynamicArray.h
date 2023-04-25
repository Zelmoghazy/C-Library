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

/*Utilities*/
void delay(int64_t ms);
void LogColor(char *text, char c);
void Swap(int64_t *a, int64_t *b);
int64_t Randomize(int64_t start, int64_t end);
void Shuffle(int64_t *array, int64_t n);
/*Dynamic Array*/
DynamicArray *newArray(int64_t initialSize);
void FreeArray(DynamicArray *DA);
bool isEmpty(DynamicArray *DA);
void PrintArray(DynamicArray *DA, int64_t start, int64_t final);
void Expand(DynamicArray *DA);
void Shrink(DynamicArray *DA);
void Append(DynamicArray *DA, int64_t value);
void Pop(DynamicArray *DA);
/*Array*/
void InsertArray(DynamicArray *DA, int64_t value, int64_t index);
void RemoveArray(DynamicArray *DA, int64_t index);
void RemoveArrayValue(DynamicArray *DA, int64_t value);
void RemoveArrayRange(DynamicArray *DA, int64_t start, int64_t end);
int64_t GetArray(DynamicArray *DA, int64_t index);
int64_t GetSize(DynamicArray *DA);
void ChangeArray(DynamicArray *DA, int64_t value, int64_t index);
void ClearArray(DynamicArray *DA, int64_t newSize);
void CopyArray(DynamicArray *DA1, DynamicArray *DA2, int64_t start, int64_t end);
void ReverseArray(DynamicArray *DA);

int64_t BinarySearch(DynamicArray *DA, int64_t value, bool first);
int64_t Count(int64_t const *A, int64_t value);

int64_t MedianOfThree(int64_t *A, int64_t left, int64_t right);
int64_t Partition(int64_t *A, int64_t start, int64_t end);
void QuickSort(DynamicArray *DA, int64_t start, int64_t end);
void ArrayPopulator(DynamicArray *DA, ...);
int64_t Power(int64_t x, int64_t n);
void Exponentiate(DynamicArray *DA, int64_t pow);
int64_t Maximum(DynamicArray *DA);
int64_t Minimum(DynamicArray *DA);