#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint64_t factorialTR(int n, int a)
{
    if (n <= 1)
    {
        return a;
    }
    else
    {
        return (factorialTR((n - 1), (a * n)));
    }
}
uint64_t factorial(uint64_t n)
{
    if (n <= 1)
    {
        return 1;
    }
    return factorialTR(n, 1);
}

int main(void)
{
    printf("%llu\n", factorial(5));
    system("pause");
    return 0;
}