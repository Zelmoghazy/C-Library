#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
uint64_t factorial(uint64_t n)
{

    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        n = n * factorial(n - 1);
    }
    return n;
}

int main(void)
{
    printf("%llu\n", factorial(19));
    system("pause");
    return 0;
}