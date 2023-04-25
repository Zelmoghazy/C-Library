#include <stdio.h>
#include <stdlib.h>

int rvr(char *s)
{
    int f = 1;
    int start = 0;
    int end;
    while (f)
    {
        for (end = start; *(s + end) != ' '; end++)
        {
            if (*(s + end) == '\0')
            {
                f = 0;
                break;
            }
        }
        int i;
        int n;
        int l = end - start;
        char c[l];
        for (i = 0, n = end; i<l, n> start; i++, n--)
        {
            *(c + i) = *(s + (n - 1));
            printf("%c", *(c + i));
        }
        end++;
        start = end;
        if (f == 0)
        {
            printf("\n");
        }
        else
        {
            printf(" ");
        }
    }
}

int main()
{
    char p[] = "Lorem ipsum, dolor sit amet consectetur adipisicing elit. Maxime, laborum. Debitis, natus vero atque eius veritatis similique consequatur repellat cupiditate non tempore! Qui atque alias quam nesciunt reiciendis est saepe.";
    rvr(p);
    system("pause");
    return 0;
}