#include <stdio.h>
#include <stdlib.h>
int main()
{
    int A = 1;
    int B = 1;
    int C = 1;
    int D = 1;
    for (int i = 0; i < 16; i++)
    {
        if (i % 2 == 0)
        {
            D = 0;
            C = !C;
        }
        else
        {
            D = 1;
        }
        if (i % 4 == 0)
        {
            B = !B;
        }
        if (i % 8 == 0)
        {
            A = !A;
        }
        printf("%d %d %d %d\n", A, B, C, D);
    }
    system("pause");
    return 0;
}