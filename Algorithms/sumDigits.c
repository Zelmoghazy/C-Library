#include <stdio.h>
#include <stdlib.h>

int sum_digits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    int n = 123456789;
    printf("%d\n", sum_digits(n));
    system("pause");
    return 0;
}