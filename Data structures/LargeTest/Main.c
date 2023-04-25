#include "DynamicArray.h"

int main()
{
    DynamicArray *a1 = newArray(100);
    ArrayPopulator(a1);
    Append(a1, 5);
    Append(a1, 6);
    Append(a1, 7);
    Append(a1, 8);
    Append(a1, 9);
    PrintArray(a1, 0, a1->end);
    printf("Maximum = %lld\n", Maximum(a1));
    printf("Minimum = %lld\n", Minimum(a1));
    FreeArray(a1);
    system("pause");
    return 0;
}