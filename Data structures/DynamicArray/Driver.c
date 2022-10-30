#include "DynamicArray.h"

int main()
{
    DynamicArray a1;
    InitArray(&a1, 5);
    Append(&a1, 0);
    Append(&a1, 1);
    Append(&a1, 2);
    Append(&a1, 3);
    InsertArray(&a1, 0, 0);
    InsertArray(&a1, 1, 0);
    InsertArray(&a1, 2, 0);
    InsertArray(&a1, 3, 0);
    InsertArray(&a1, 4, 0);
    Pop(&a1);
    Pop(&a1);
    Pop(&a1);
    Pop(&a1);
    PrintArray(&a1, 0, a1.end);
    FreeArray(&a1);

    system("pause");
    return 0;
}