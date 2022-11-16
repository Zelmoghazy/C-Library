#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int FibRecTR(int n, int a, int b)
{
    if (n == 0)
    {
        return a;
    }
    else if (n == 1)
    {
        return b;
    }
    else
    {
        return FibRecTR((n - 1), b, (a + b));
    }
}
int FibRec(int n)
{
    return FibRecTR(n, 0, 1);
}
int main()
{
    printf("%d\n", FibRec(2));

    system("pause");
    return 0;
}