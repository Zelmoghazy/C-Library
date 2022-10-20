#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
} Node;

void InsertAtHead(Node **ptrhead, int data)
{
  Node *newNodeptr = (Node *)malloc(sizeof(Node));
  newNodeptr->data = data;
  newNodeptr->prev = NULL;
  newNodeptr->next = NULL;

  if (*ptrhead == NULL)
  { // Empty List
    *ptrhead = newNodeptr;
    return;
  }
  (*ptrhead)->prev = newNodeptr;
  newNodeptr->next = *ptrhead;
  *ptrhead = newNodeptr;
}

void InsertAtTail(Node **ptrhead, int data)
{
  Node *newNodeptr = (Node *)malloc(sizeof(Node));
  newNodeptr->data = data;
  newNodeptr->prev = NULL;
  newNodeptr->next = NULL;
  Node *last = *ptrhead;

  if (*ptrhead == NULL)
  { // Empty List
    newNodeptr->prev = NULL;
    *ptrhead = newNodeptr;
    return;
  }
  while (last->next != NULL)
  {
    last = last->next;
  }
  last->next = newNodeptr;
  newNodeptr->prev = last;
}

void Insert(Node **ptrhead, int data, int n)
{

  Node *newNode = (Node *)malloc(sizeof(Node));
  Node *temp = *ptrhead;
  int i = 1;
  while (i < n - 1 && temp != NULL)
  {
    temp = temp->next;
    i++;
  }
  if (n == 1)
  {
    InsertAtHead(ptrhead, data);
  }
  else if (temp->next == NULL)
  {
    InsertAtTail(ptrhead, data);
  }
  else if (temp != NULL)
  {
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
      temp->next->prev = newNode;
    }
    temp->next = newNode;
  }
}
void deleteNode(Node **ptrhead, int n)
{
  /* if list is NULL or invalid position is given */
  if (*ptrhead == NULL || n <= 0)
  {
    printf("invalid \n");
    return;
  }

  struct Node *current = *ptrhead;
  /* traverse up to the node at position 'n' from the beginning */
  for (int i = 1; current != NULL && i < n; i++)
  {
    current = current->next;
  }

  /* if 'n' is greater than the number of nodes
     in the doubly linked list */
  if (current == NULL)
  {
    printf("Cant delete Node doesnt exist \n");
    return;
  }

  /* If node to be deleted is head node */
  if (*ptrhead == current)
  {
    *ptrhead = current->next;
  }

  /* Change next only if node to be deleted is NOT
     the last node */
  if (current->next != NULL)
  {
    current->next->prev = current->prev;
  }

  /* Change prev only if node to be deleted is NOT
     the first node */
  if (current->prev != NULL)
  {
    current->prev->next = current->next;
  }

  /* Finally, free the memory occupied by current*/
  free(current);
}

void Print(Node *head)
{
  if (head == NULL)
  {
    return;
  }
  while (head != NULL)
  {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

void PrintRev(Node *head)
{
  if (head == NULL)
  {
    return;
  }
  while (head->next != NULL)
  {
    head = head->next;
  }
  while (head != NULL)
  {
    printf("%d ", head->data);
    head = head->prev;
  }
  printf("\n");
}

int main()
{
  Node *head = NULL;
  InsertAtTail(&head, 5);
  InsertAtTail(&head, 4);
  InsertAtTail(&head, 3);
  InsertAtTail(&head, 6);
  InsertAtTail(&head, 8);
  InsertAtTail(&head, 7);
  InsertAtTail(&head, 2);
  InsertAtTail(&head, 1);
  deleteNode(&head, 8);
  Insert(&head, 9, 3);
  Insert(&head, 7, 1);
  Print(head);
  system("pause");
  return 0;
}