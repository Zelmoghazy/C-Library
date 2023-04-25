#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    Node *head;
    int size;
} LinkedList;

LinkedList *NewLinkedList()
{
    LinkedList *L = (LinkedList *)malloc(sizeof(LinkedList));
    L->head = NULL;
    L->size = 0;
    return L;
}

void Print(LinkedList *L)
{
    Node *current = L->head;
    while (current->next != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("%d", current->data);
    printf("\n");
}

void PrtRvr(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    PrtRvr(head->next);
    printf("%d ", head->data);
}

void PrintRvr(LinkedList *L)
{
    PrtRvr(L->head);
    printf("\n");
}

bool IsEmpty(LinkedList *L)
{
    return (L->head == NULL);
}

int Length(LinkedList *L)
{
    Node *current = L->head;
    int length = 0;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}

void PushFront(LinkedList *L, int data)
{
    Node *newhead = (Node *)malloc(sizeof(Node));
    newhead->data = data;
    newhead->next = L->head;
    L->head = newhead;
    L->size++;
}

void PushBack(LinkedList *L, int data)
{
    if (IsEmpty(L))
    {
        PushFront(L, data);
    }
    else
    {
        Node *LastNode = L->head;
        while (LastNode->next != NULL)
        {
            // traverse the linked list to last node
            LastNode = LastNode->next;
        }
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        LastNode->next = newNode;
        L->size++;
    }
}

void Insert(LinkedList *L, int data, int index)
{
    if (IsEmpty(L))
    {
        PushFront(L, data);
    }
    if (index == 1) // insert at first position
    {
        PushFront(L, data);
        return;
    }
    else if (index > L->size)
    {
        PushBack(L, data);
        return;
    }

    Node *ReqNode = L->head;

    for (int i = 0; i < index - 2; i++)
    { // traverse to (index-1)th node
        ReqNode = ReqNode->next;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = ReqNode->next;
    ReqNode->next = newNode;
    L->size++;
}

void PopFront(LinkedList *L)
{
    if (IsEmpty(L))
    {
        return;
    }
    Node *delhead = L->head;
    L->head = delhead->next;
    free(delhead);
    L->size--;
}

void PopBack(LinkedList *L)
{
    if (IsEmpty(L))
    {
        return;
    }
    if (L->head->next == NULL)
    {
        free(L->head);
        L->head = NULL;
        return;
    }

    Node *LastNode = L->head;
    Node *PrevNode = L->head;
    while (LastNode->next != NULL)
    {
        PrevNode = LastNode;       // point to before last node
        LastNode = LastNode->next; // point too last node
    }
    PrevNode->next = NULL;
    free(LastNode);
    LastNode = NULL;
    L->size--;
}

void Remove(LinkedList *L, int index)
{
    if (IsEmpty(L))
    {
        return;
    }
    if (L->head->next == NULL)
    {
        free(L->head);
        L->head = NULL;
        return;
    }
    if (index == 1)
    {
        PopFront(L);
        return;
    }
    else if (index >= L->size)
    {
        PopBack(L);
        return;
    }
    Node *PrevNode = L->head;
    for (int i = 0; i < index - 2; i++)
    {
        PrevNode = PrevNode->next;
        // temp points to (index-1)th Node
    }
    Node *DelNode = PrevNode->next; // nth node
    PrevNode->next = DelNode->next; //(index+1)th node
    free(DelNode);
}

void Reverse(LinkedList *L)
{
    if (L->head == NULL || L->head->next == NULL)
    {
        return;
    }
    Node *current = L->head;
    Node *prev = NULL;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    L->head = prev;
}

void RevRec(Node **ptrhead)
{
    if ((*ptrhead)->next == NULL || *ptrhead == NULL)
    {
        return; // exit condition from recursion
    }
    Node *current = *ptrhead;
    *ptrhead = (*ptrhead)->next;
    RevRec(ptrhead);
    current->next->next = current;
    current->next = NULL;
}

void ReverseRec(LinkedList *L)
{
    RevRec(&(L->head));
}

int Contains(LinkedList *L, int data)
{
    int n = 1;
    Node *temp = L->head;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return n;
        }
        temp = temp->next;
        n++;
    }
    return -1;
}

void FreeLinkedList(LinkedList *L)
{
    while (!IsEmpty(L))
    {
        PopFront(L);
    }
    free(L);
}

Node *MergeLinkedListNodes(Node *first, Node *second)
{
    Node *result = NULL;
    if (first == NULL)
    {
        return second;
    }
    if (second == NULL)
    {
        return first;
    }

    if (first->data <= second->data)
    {
        result = first;
        result->next = MergeLinkedListNodes(first->next, second);
    }
    else
    {
        result = second;
        result->next = MergeLinkedListNodes(first, second->next);
    }
    return result;
}

void MergeSortLinkedListNode(Node **head)
{
    if ((*head) == NULL || (*head)->next == NULL)
    {
        return;
    }
    Node *curr = *head;
    Node *slow = curr;
    Node *fast = curr->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    Node *l1 = curr;
    Node *l2 = slow->next;
    slow->next = NULL;
    MergeSortLinkedListNode(&l1);
    MergeSortLinkedListNode(&l2);
    *head = MergeLinkedListNodes(l1, l2);
}

void MergeSortLinkedList(LinkedList *L)
{
    MergeSortLinkedListNode(&(L->head));
}
