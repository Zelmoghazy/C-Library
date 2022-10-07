#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/*
if N is even,
we have X^N = X^{N/2} · X^{N/2},
and if N is odd,
X^{N} = X^{(N−1)/2} · X^{(N−1)/2} · X
*/

uint64_t power(uint64_t x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return power(x * x, n / 2);
    }
    else
    {
        return power(x * x, n / 2) * x;
    }
}

int main()
{
    printf("%llu\n", power(200, 15));
    system("pause");
    return 0;
}