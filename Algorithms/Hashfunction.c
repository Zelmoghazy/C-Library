#include <stdio.h>
#include <stdlib.h>

unsigned int multiplicative_hash(int key, int m) {
    float a = 0.6180339887;
    float product = key * a;
    float fractional_part = product - (int)product; // Extract the fractional part of the product
    unsigned int hash = (unsigned int)(m * fractional_part); // Multiply the fractional part by m and truncate to integer
    return hash;
}

int main() {
    int key = 1234;
    int r = 15896;
    unsigned int hash = multiplicative_hash(key, r);
    printf("Key: %d, Hash: %u\n", key, hash);
    system("pause");
    return 0;
}
