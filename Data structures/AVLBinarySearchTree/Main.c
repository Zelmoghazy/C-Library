
#include "BinarySearchTree.h"

int main()
{
    BST *T1 = newBST();
    Insert(T1, 10);
    Insert(T1, 20);
    Insert(T1, 30);
    Insert(T1, 40);
    Insert(T1, 50);
    Insert(T1, 60);
    Insert(T1, 9);
    Insert(T1, 8);
    Insert(T1, 7);
    Insert(T1, 6);
    Insert(T1, 5);
    Delete(T1, 5);
    Delete(T1, 6);
    Delete(T1, 7);
    Delete(T1, 8);
    preorderTraversal(T1);
    FreeBST(T1);

    system("pause");
    return 0;
}