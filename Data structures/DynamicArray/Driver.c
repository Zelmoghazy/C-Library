#include "DynamicArray.h"

int main()
{
    DynamicArray a1;
    InitArray(&a1, 100);
    InsertArray(&a1, 5, a1.end);
    InsertArray(&a1, 5, a1.end);
    InsertArray(&a1, 5, a1.end);
    InsertArray(&a1, 5, a1.end);
    InsertArray(&a1, 6, a1.end);
    InsertArray(&a1, 6, a1.end);
    InsertArray(&a1, 6, a1.end);
    InsertArray(&a1, 5, a1.end);
    InsertArray(&a1, 8, a1.end);
    InsertArray(&a1, 7, a1.end);
    InsertArray(&a1, 6, a1.end);
    InsertArray(&a1, 9, a1.end);
    InsertArray(&a1, 6, a1.end);
    InsertArray(&a1, 10, a1.end);
    RemoveArrayRange(&a1, 0, 4);
    PrintArray(&a1, 0, a1.end);
    FreeArray(&a1);

    system("pause");
    return 0;
}