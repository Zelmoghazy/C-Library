#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *Left;
    struct Node *Right;
} Node;

typedef struct BST
{
    Node *root; // root node
} BST;

void Init(BST *T)
{
    T->root = NULL;
}
Node *GetNewNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->Left = NULL;
    newNode->Right = NULL;
    return newNode;
}
void InsertinNode(Node **root, int data)
{
    if (*root == NULL) // Empty Tree
    {
        *root = GetNewNode(data);
    }
    else if ((*root)->data >= data)
    {
        InsertinNode(&((*root)->Left), data);
    }
    else
    {
        InsertinNode(&((*root)->Right), data);
    }
}

void Insert(BST *T, int data)
{
    InsertinNode(&(T->root), data);
}

bool SearchinNode(Node **root, int data)
{
    if (*root == NULL)
    {
        return false;
    }
    else if ((*root)->data == data)
    {
        return true;
    }
    else if (data <= (*root)->data)
    {
        return SearchinNode(&((*root)->Left), data);
    }
    else
    {
        return SearchinNode(&((*root)->Right), data);
    }
}

bool Search(BST *T, int data)
{
    return SearchinNode(&(T->root), data);
}

Node *minValueNode(Node *node)
{
    Node *temp = node;
    while (temp && temp->Left != NULL)
    {
        temp = temp->Left;
    }
    return temp;
}
void DeleteinNode(Node **root, int data)
{
    if ((*root) == NULL)
    {
        return;
    }
    if (data < (*root)->data)
    {
        DeleteinNode(&((*root)->Left), data);
    }
    else if (data > (*root)->data)
    {
        DeleteinNode(&((*root)->Right), data);
    }
    else
    {
        if ((*root)->Left == NULL)
        {
            Node *temp = (*root)->Right;
            free(*root);
            *root = temp;
            return;
        }
        else if ((*root)->Right == NULL)
        {
            Node *temp = (*root)->Left;
            free(*root);
            *root = temp;
            return;
        }
        Node *temp = minValueNode((*root)->Right);
        (*root)->data = temp->data;
        DeleteinNode(&((*root)->Right), temp->data);
    }
    return;
}

void Delete(BST *T, int data)
{
    DeleteinNode(&(T->root), data);
}

int Min(BST *T)
{
    if (T->root == NULL)
    {
        printf("Tree is empty");
        return -1;
    }

    Node *current = T->root;
    while (current->Left != NULL)
    {
        current = current->Left;
    }
    return current->data;
}
int Max(BST *T)
{
    if (T->root == NULL)
    {
        printf("Tree is empty");
        return -1;
    }

    Node *current = T->root;
    while (current->Right != NULL)
    {
        current = current->Right;
    }
    return current->data;
}
int FindMax(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int FindHeightNode(Node **root)
{
    if (*root == NULL)
    {
        return -1;
    }
    int leftHeight = FindHeight(&((*root)->Left));
    int rightHeight = FindHeight(&((*root)->Right));
    return FindMax(leftHeight, rightHeight) + 1;
}

int FindHeight(BST *T)
{
    return FindHeightNode(&(T->root));
}

bool isBSTUtil(Node **root, int min, int max)
{
    if ((*root) == NULL)
    {
        return true;
    }
    if ((*root)->data < min || (*root)->data > max)
    {
        return false;
    }
    return isBSTUtil(&((*root)->Left), min, (*root)->data - 1) && isBSTUtil(&((*root)->Right), (*root)->data + 1, max);
}

bool isBST(BST *T)
{
    return isBSTUtil(&(T->root), INT_MIN, INT_MAX);
}
void preorderTraversalnode(Node **root)
{
    if ((*root) == NULL)
    {
        return;
    }
    printf("%d -> ", (*root)->data);
    preorderTraversalnode(&((*root)->Left));
    preorderTraversalnode(&((*root)->Right));
}
void preorderTraversal(BST *T)
{
    preorderTraversalnode(&(T->root));
    printf("\n");
}
void inorderTraversalnode(Node **root)
{
    if ((*root) == NULL)
    {
        return;
    }
    inorderTraversalnode(&((*root)->Left));
    printf("%d -> ", (*root)->data);
    inorderTraversalnode(&((*root)->Right));
}

void inorderTraversal(BST *T)
{
    inorderTraversalnode(&(T->root));
    printf("\n");
}

int main()
{
    BST *T1;
    Init(&T1);
    Insert(&T1, 50);
    Insert(&T1, 30);
    Insert(&T1, 20);
    Insert(&T1, 40);
    Insert(&T1, 70);
    Insert(&T1, 60);
    Insert(&T1, 80);

    inorderTraversal(&T1);

    Delete(&T1, 50);
    inorderTraversal(&T1);

    printf("%d\n", FindHeight(&T1));
    printf("%d\n", isBST(&T1));
    system("pause");
    return 0;
}