#include <stdio.h>
#include <stdlib.h>

void towers_of_hanoi(int n, char from, char to, char temp)
{
    if (n == 0)
    {
        return;
    }
    towers_of_hanoi(n - 1, from, temp, to);
    printf("Move disk %d from rod %c to rod %c\n", n, from, to);
    towers_of_hanoi(n - 1, temp, to, from);
}
int main()
{
    int n = 4;
    towers_of_hanoi(n, 'A', 'C', 'B');
    system("pause");
    return 0;
}