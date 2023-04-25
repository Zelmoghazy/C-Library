#include <stdio.h>
#include <stdlib.h>

double squareRoot(int number, int precision)
{
    if (number == 0 || number == 1)
    {
        return number;
    }
    if (number < 0)
    {
        return -1;
    }
    int start = 0;
    int end = number / 2; // sqrt is always <= number/2
    double result;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (mid * mid == number)
        {
            return mid;
        }
        if (mid * mid < number)
        {
            start = mid + 1;
            result = mid;
        }
        else
        {
            end = mid - 1;
        }
    }
    double increment = 0.1;
    for (int i = 0; i < precision; i++)
    {
        while (result * result <= number)
        {
            result += increment;
        }

        // loop terminates when result * result > number
        result = result - increment;
        increment = increment / 10;
    }
    return result;
}

int main()
{
    printf("%lf\n", squareRoot(3, 3));
    system("pause");
    return 0;
}