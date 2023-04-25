#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int PowMod(int a, int n, int b)
{
    if (b == 1)
    {
        return 0;
    }
    int result = 1;
    a = a % b;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            result = (result * a) % b;
        }
        a = (a * a) % b;
        n = floor(n / 2);
    }
    return result;
}

int main()
{
    printf("%d\n", PowMod(23, 373, 747));
    system("pause");
    return 0;
}