#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    int x = 5;

    for (i = 1; i < 1000; ++i)
    {
        if (((i % 10) / 1) == 3 || ((i % 100) / 10) == 3 || ((i % 1000) / 100) == 3)
        {
            printf("%d \n", i);
        }

        else if (((i % 10) / 1) == 4 || ((i % 100) / 10) == 4 || ((i % 1000) / 100) == 4)
        {
            printf("%d \n", i);
        }
        else
        {
        }
    }
    system("pause");
    return 0;
}
