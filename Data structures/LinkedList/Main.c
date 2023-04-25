#include "LinkedList.h"

int main()
{
    LinkedList *l1 = NewLinkedList();
    for (int i = 10; i > 0; i--)
    {
        PushFront(l1, i);
    }
    Print(l1);
    FreeLinkedList(l1);
    system("pause");
    return 0;
}