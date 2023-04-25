#include <stdio.h>
#include <stdlib.h>

unsigned int isqrt(unsigned int y)
{
    unsigned int L = 0;
    unsigned int M;
    unsigned int R = y + 1;

    while (L != R - 1)
    {
        M = (L + R) / 2;

        if (M * M <= y)
            L = M;
        else
            R = M;
    }

    return L;
}


int main()
{
    sqrtForever(2);
    printf("\n");
    system("pause");
    return 0;
}