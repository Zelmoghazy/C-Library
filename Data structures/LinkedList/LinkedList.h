#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;
typedef struct LinkedList LinkedList;

LinkedList *NewLinkedList();
void Print(LinkedList *L);
void PrtRvr(Node *head);
void PrintRvr(LinkedList *L);
bool IsEmpty(LinkedList *L);
int Length(LinkedList *L);
void PushFront(LinkedList *L, int data);
void PushBack(LinkedList *L, int data);
void Insert(LinkedList *L, int data, int index);
void PopFront(LinkedList *L);
void PopBack(LinkedList *L);
void Remove(LinkedList *L, int index);
void Reverse(LinkedList *L);
void RevRec(Node **ptrhead);
void ReverseRec(LinkedList *L);
int Contains(LinkedList *L, int data);
void FreeLinkedList(LinkedList *L);
Node *MergeLinkedListNodes(Node *first, Node *second);
void MergeSortLinkedListNode(Node **head);
void MergeSortLinkedList(LinkedList *L);
