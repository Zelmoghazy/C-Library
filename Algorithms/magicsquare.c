#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool isValid(const int *A, int n)
{
    int height = (int)sqrt(n);
    int expected = 0;
    for (int i = 0; i < height; i++)
    {
        expected += A[i];
    }
    // rows
    for (int i = 0; i < n; i = i + height)
    {
        int sum = 0;
        for (int j = i; j < i + height; j++)
        {
            sum += A[j];
        }
        if (sum != expected)
        {
            return false;
        }
    }
    // columns
    for (int i = 0; i < height; i++)
    {
        int sum = 0;
        for (int j = i; j <= i + (height - 1) * height; j = j + height)
        {
            sum += A[j];
        }
        if (sum != expected)
        {
            return false;
        }
    }
    // Diagonals
    int sum = 0;
    for (int i = 0, sum = 0; i < height; i++)
    {
        sum += A[i * height + i];
    }
    if (sum != expected)
    {
        return false;
    }
    sum = 0;
    for (int i = 0; i < height; i++)
    {
        sum += A[height - 1 + i * (height - 1)];
    }
    if (sum != expected)
    {
        return false;
    }
    return true;
}

int main()
{
    // for 3x3 matrix
    int A[9] = {0};
    int n = 9;
    int centernumber = 5;
    int centerindex = n / 2;

    // Initialize the matrix from constraints
    for (int i = 0, j = 2; i < n; i += 2, j += 2)
    {
        if (i == centerindex)
        {
            A[i] = centernumber;
            j -= 2;
            continue;
        }
        A[i] = j;
    }
    for (int i = 1, j = 1; i < n; i += 2, j += 2)
    {
        if (j == centernumber)
        {
            i -= 2;
            continue;
        }
        A[i] = j;
    }
    //----------------------------------
    system("pause");
    return 0;
}