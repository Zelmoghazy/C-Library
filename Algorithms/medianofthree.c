#include <stdio.h>
#include <stdlib.h>

int m3(int a, int b, int c)
{
    if (a > b)
    {
        if (b > c)
        {
            return b;
        }
        else if (a > c)
        {
            return c;
        }
        else
        {
            return a;
        }
    }
    else
    {
        if (a > c)
        {
            return a;
        }
        else if (b > c)
        {
            return c;
        }
        else
        {
            return b;
        }
    }
}

int main()
{

    system("pause");
    return 0;
}