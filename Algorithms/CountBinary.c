#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
int count_binary_digits_recursively(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return count_binary_digits_recursively(floor(n / 2)) + 1;
    }
}

int main()
{
    int n = 16;
    printf("The number of binary digits in %d is %d.\n", n, count_binary_digits_recursively(n));
    system("pause");
    return 0;
}