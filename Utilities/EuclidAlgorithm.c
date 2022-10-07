#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Euclid’s algorithm for computing the greatest common divisor.
// The greatest common divisor (gcd) of two integers
// is the largest integer that divides both. 

uint64_t gcd(uint64_t m, uint64_t n)
{
    while (n != 0)
    {
        uint64_t rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}
int main()
{
    printf("%llu\n", gcd(150, 15));
    system("pause");
    return 0;
}