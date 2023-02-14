#include "BinarySearchTree.h"

BST *newBST()
{
    BST *T = (BST *)malloc(sizeof(BST));
    T->root = NULL;
    return T;
}
Node *GetNewNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->height = 1;
    newNode->Left = NULL;
    newNode->Right = NULL;
    return newNode;
}
int NodeHeight(Node *root)
{
    int hl;
    int hr;
    if (root != NULL && root->Left != NULL)
    {
        hl = root->Left->height;
    }
    else
    {
        hl = 0;
    }
    if (root != NULL && root->Right != NULL)
    {
        hr = root->Right->height;
    }
    else
    {
        hr = 0;
    }
    return hl > hr ? hl + 1 : hr + 1;
}

int BalanceFactor(Node *root)
{
    int hl;
    int hr;
    if (root != NULL && root->Left != NULL)
    {
        hl = root->Left->height;
    }
    else
    {
        hl = 0;
    }
    if (root != NULL && root->Right != NULL)
    {
        hr = root->Right->height;
    }
    else
    {
        hr = 0;
    }
    return hl - hr;
}
void LLrotation(Node **root)
{
    Node *l = (*root)->Left;
    Node *lr = l->Right;
    l->Right = (*root);
    (*root)->Left = lr;
    (*root)->height = NodeHeight((*root));
    l->height = NodeHeight(l);
    (*root) = l;
}
void RRrotation(Node **root)
{
    Node *r = (*root)->Right;
    Node *rl = r->Left;
    r->Left = (*root);
    (*root)->Right = rl;
    (*root)->height = NodeHeight((*root));
    r->height = NodeHeight(r);
    (*root) = r;
}

void LRrotation(Node **root)
{
    Node *l = (*root)->Left;
    Node *lr = l->Right;
    l->Right = lr->Left;
    (*root)->Left = lr->Right;
    lr->Left = l;
    lr->Right = *root;
    l->height = NodeHeight(l);
    (*root)->height = NodeHeight(*root);
    lr->height = NodeHeight(lr);
    (*root) = lr;
}

void RLrotation(Node **root)
{
    Node *r = (*root)->Right;
    Node *rl = r->Left;

    r->Left = rl->Right;
    (*root)->Right = rl->Left;
    rl->Right = r;
    rl->Left = *root;
    r->height = NodeHeight(r);
    (*root)->height = NodeHeight(*root);
    rl->height = NodeHeight(rl);
    (*root) = rl;
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
    (*root)->height = NodeHeight(*root);
    if (BalanceFactor(*root) == 2 && BalanceFactor((*root)->Left) == 1)
    {
        LLrotation(root);
    }
    else if (BalanceFactor(*root) == 2 && BalanceFactor((*root)->Left) == -1)
    {
        LRrotation(root);
    }
    else if (BalanceFactor(*root) == -2 && BalanceFactor((*root)->Right) == -1)
    {
        RRrotation(root);
    }
    else if (BalanceFactor(*root) == -2 && BalanceFactor((*root)->Right) == 1)
    {
        RLrotation(root);
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

    (*root)->height = NodeHeight(*root);

    if (BalanceFactor(*root) == 2 && BalanceFactor((*root)->Left) == 1)
    {
        LLrotation(root);
    }
    else if (BalanceFactor(*root) == 2 && (BalanceFactor((*root)->Left) == -1 || BalanceFactor((*root)->Left) == 0))
    {
        LRrotation(root);
    }
    else if (BalanceFactor(*root) == -2 && BalanceFactor((*root)->Right) == -1)
    {
        RRrotation(root);
    }
    else if (BalanceFactor(*root) == -2 && (BalanceFactor((*root)->Right) == 1 || BalanceFactor((*root)->Right) == 0))
    {
        RLrotation(root);
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

void postorderTraversalnode(Node **root)
{
    if ((*root) == NULL)
    {
        return;
    }
    postorderTraversalnode(&((*root)->Left));
    postorderTraversalnode(&((*root)->Right));
    printf("%d -> ", (*root)->data);
}

void postorderTraversal(BST *T)
{
    postorderTraversalnode(&(T->root));
    printf("\n");
}

int Count_Leaves_Nodes(Node **root)
{
    if ((*root)->Left == NULL && (*root)->Right == NULL)
    {
        return 1;
    }
    int l = 0;
    if ((*root)->Left != NULL)
    {
        l += Count_Leaves_Nodes(&((*root)->Left));
    }
    if ((*root)->Right != NULL)
    {
        l += Count_Leaves_Nodes(&((*root)->Right));
    }
    return l;
}

int Count_Leaves(BST *T)
{
    Count_Leaves_Nodes(&(T->root));
}

void FreeAllNodes(Node **root)
{
    if ((*root) == NULL)
    {
        return;
    }
    FreeAllNodes(&((*root)->Left));
    FreeAllNodes(&((*root)->Right));
    free(*root);
}

void FreeBST(BST *T)
{
    FreeAllNodes(&(T->root));
    free(T);
}

int Count_Nodes_Util(Node **root)
{
    if ((*root) == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + Count_Nodes_Util(&((*root)->Left)) + Count_Nodes_Util(&((*root)->Left));
    }
}

int Count_nodes(BST *T)
{
    int n = Count_Nodes_Util(&(T->root));
    return n;
}
