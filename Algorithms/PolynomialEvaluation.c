#include <stdio.h>
#include <stdlib.h>

int polyEvaluate(int coeff[], int order, int x)
{
    int result = 0;
    int power = 1;
    for (int i = 0; i <= order; i++)
    {
        result += coeff[i] * power;
        power = power * x;
    }
    return result;
}

int main()
{
    int coeff[] = {5, 4, 6, 5};
    int order = 3;
    printf("%d\n", polyEvaluate(coeff, order, 5));
    system("pause");
    return 0;
}