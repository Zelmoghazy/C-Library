#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countChars(char *A, char c, int start, int end)
{
    if (start == end)
    {
        if (A[start] == c)
        {
            return 1;
        }
        return 0;
    }
    int mid = (start + end) / 2;
    return countChars(A, c, start, mid) + countChars(A, c, mid + 1, end);
}
int main()
{
    char *A = "Zehad";
    printf("%d\n", countChars(A, 'Z', 0, strlen(A)));
    system("pause");
    return 0;
}