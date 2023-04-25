#include <ctype.h>
#include <stdio.h>

void reverse(char *from)
{
    for (;;)
    {
        char *start, *end;

        for (start = from; *start && isspace(*start); start++)
        {
        }
        for (end = start; *end && !isspace(*end); end++)
        {
        }
        if (!*start)
            break;

        from = end;
        end--;

        while (start < end)
        {
            char t = *start;
            *start = *end;
            *end = t;
            start++;
            end--;
        }
    }
}

int main(void)
{
    char s[] = "Lorem ipsum, dolor sit amet consectetur adipisicing elit. Maxime, laborum. Debitis, natus vero atque eius veritatis similique consequatur repellat cupiditate non tempore! Qui atque alias quam nesciunt reiciendis est saepe.";
    reverse(s);
    printf("%s\n", s);
    system("pause");
    return 0;
}