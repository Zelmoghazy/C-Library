#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    struct Node *front; // front node pointer
    struct Node *rear;  // tail node pointer
} Queue;

void QueueInit(Queue *Q)
{
    Q->front = NULL;
    Q->rear = NULL;
}

void enQueue(Queue *Q, int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = Q->front;
    if (Q->rear == NULL)
    {
        Q->front = Q->rear = temp;
        return;
    }
    Q->rear->next = temp;
    Q->rear = temp;
}

void deQueue(Queue *Q, int x)
{
    if (Q->front == NULL)
    {
        return;
    }
    Node *temp = Q->front;
    Q->front = Q->front->next;
    if (Q->front == NULL)
    {
        Q->rear = NULL;
    }
    free(temp);
}

int main()
{

    system("pause");
    return 0;
}