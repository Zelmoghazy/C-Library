
#include "DynamicArray.h"

int main()
{
    DynamicArray a1;

    InitArray(&a1, 10);
    ArrayPopulator(&a1, 0, 10, 'b');
    PrintArray(&a1, 0, a1.end);
    QuickSort(&a1, 0, a1.end);
    PrintArray(&a1, 0, a1.end);

    printf("%d\n", BinarySearch(&a1, 9, true));
    InsertArray(&a1, 11, a1.end);
    PrintArray(&a1, 0, a1.end);

    FreeArray(&a1);

    system("pause");
    return 0;
}