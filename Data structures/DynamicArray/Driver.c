#include "DynamicArray.h"

int main()
{
    DynamicArray *a1 = newArray(100);
    ArrayPopulator(a1, 'r', 0, 64);
    PrintArray(a1, 0, a1->end);
    printf("Maximum = %d\n", Maximum(a1));
    printf("Minimum = %d\n", Minimum(a1));
    FreeArray(a1);
    system("pause");
    return 0;
}