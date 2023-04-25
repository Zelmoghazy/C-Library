#include <stdio.h>
#include <stdlib.h>

int count_binary_digits(int n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 2;
        count++;
    }
    return count;
}

void Binary(int n)
{
    int numberOfDigits = count_binary_digits(n);
    int *B = malloc(numberOfDigits * sizeof(int));
    for (int i = 0; n > 0; i++)
    {
        B[i] = n % 2;
        n = n / 2;
    }
    for (int i = numberOfDigits - 1; i >= 0; i--)
    {
        printf("%d ", B[i]);
    }
    printf("\n");
    free(B);
}

int main()
{
    Binary(127);
    system("pause");
    return 0;
}