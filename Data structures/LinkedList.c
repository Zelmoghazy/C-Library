#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;          // 4 bytes
    struct Node *next; // 4 bytes
} Node;

void Print(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void PrintRvr(Node *head)
{
    if (head == NULL)
    {
        printf("\n");
        return;
    }
    PrintRvr(head->next);
    printf("%d ", head->data);
}

void Insert(Node **ptrhead, int data, int n)
{
    Node *temp1 = (Node *)malloc(sizeof(Node));

    temp1->data = data; //(*temp1).data=data
    temp1->next = NULL;

    if (n == 1) // insert at first position
    {
        temp1->next = *ptrhead;
        *ptrhead = temp1;
        return;
    }

    Node *temp2 = *ptrhead;

    for (int i = 0; i < n - 2; i++)
    { // traverse to (n-1)th node
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void Delete(Node **ptrhead, int n)
{
    Node *temp1 = *ptrhead;
    if (n == 1)
    {
        *ptrhead = temp1->next; // head now points to second node
        free(temp1);
        return;
    }
    int i;
    for (i = 0; i < n - 2; i++)
    {
        temp1 = temp1->next;
        // temp points to (n-1)th Node
    }
    Node *temp2 = temp1->next; // nth node
    temp1->next = temp2->next; //(n+1)th node
    free(temp2);
}

void Reverse(Node **ptrhead)
{
    Node *current = *ptrhead;
    Node *prev = NULL;
    Node *next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *ptrhead = prev;
}

void ReverseRec(Node **ptrhead)
{
    if ((*ptrhead)->next == NULL || *ptrhead == NULL)
    {
        return; // exit condition from recursion
    }
    Node *current = *ptrhead;
    *ptrhead = (*ptrhead)->next;
    ReverseRec(ptrhead);
    // current->next->next = current;
    Node *temp = current->next;
    temp->next = current;
    current->next = NULL;
    // current->next = NULL;
}

int main()
{
    Node *head = NULL; // create empty list
    for (int i = 1; i < 10; i++)
    {
        Insert(&head, i, i);
    }
    ReverseRec(&head);
    Print(head);
    system("pause");
    return 0;
}