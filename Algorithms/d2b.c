#include <stdio.h>
#include <stdlib.h>

void d2b(int n)
{
    if (n > 0)
    {
        d2b(n / 2);
        printf("%d", n % 2);
    }
    else
    {
        printf("0");
    }
}

int main()
{
    d2b(15);
    printf("\n");
    system("pause");
    return 0;
}