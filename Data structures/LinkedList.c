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

void Init(LinkedList *L)
{
    L->head = NULL;
    L->size = 0;
}

void Print(LinkedList *L)
{
    while (L->head != NULL)
    {
        printf("%d ", L->head->data);
        L->head = L->head->next;
    }
    printf("\n");
}

void Rvr(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Rvr(head->next);
    printf("%d ", head->data);
}

void PrintRvr(LinkedList *L)
{
    Rvr(L->head);
    printf("\n");
}

bool IsEmpty(LinkedList *L)
{
    return L->head == NULL;
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
    Node *PrevNode = NULL;
    while (LastNode->next != NULL)
    {
        PrevNode = LastNode;
        LastNode = LastNode->next;
    }
    free(LastNode);
    PrevNode->next = NULL;
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
    Node *current = L->head;
    Node *prev = NULL;
    Node *next;
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

void Clear(LinkedList *L)
{
    while (!IsEmpty(L))
    {
        PopFront(L);
    }
}

/* Takes two lists sorted in increasing order, and splices
   their nodes together to make one big sorted list which
   is returned.  */
Node *SortedMerge(Node *head1, Node *head2)
{
    /* a dummy first node to hang the result on */
    Node *dummy = (Node *)malloc(sizeof(Node));

    /* tail points to the last result node  */
    Node *prevNode = dummy;

    /* so prevNode->next is the place to add new nodes
      to the result. */
    prevNode->next = NULL;

    while (1)
    {
        if (head1 == NULL)
        {
            /* if either list runs out, use the
               other list */
            prevNode->next = head2;
            break;
        }
        else if (head2 == NULL)
        {
            prevNode->next = head1;
            break;
        }
        if (head1->data <= head2->data)
        {
            prevNode->next = head1;
            head1 = head1->next;
        }
        else
        {
            prevNode->next = head2;
            head2 = head2->next;
        }

        prevNode = prevNode->next;
    }
    Node *res = prevNode->next;
    free(dummy);
    return res;
}

int main()
{
    LinkedList l1;
    Init(&l1);
    PushBack(&l1, 0);
    PushBack(&l1, 1);
    PushBack(&l1, 2);
    PushBack(&l1, 3);
    PushBack(&l1, 4);
    ReverseRec(&l1);
    printf("%d\n", Contains(&l1, 3));

    Print(&l1);
    Clear(&l1);
    system("pause");
    return 0;
}