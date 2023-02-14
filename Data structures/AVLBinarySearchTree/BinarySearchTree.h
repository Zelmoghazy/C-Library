#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    int height;
    struct Node *Left;
    struct Node *Right;
} Node;

typedef struct BST
{
    Node *root; // root node
} BST;

BST *newBST();
Node *GetNewNode(int data);
int NodeHeight(Node *root);
int BalanceFactor(Node *root);
void LLrotation(Node **root);
void RRrotation(Node **root);
void LRrotation(Node **root);
void RLrotation(Node **root);
void InsertinNode(Node **root, int data);
void Insert(BST *T, int data);
bool SearchinNode(Node **root, int data);
bool Search(BST *T, int data);
Node *minValueNode(Node *node);
void DeleteinNode(Node **root, int data);
void Delete(BST *T, int data);
int Min(BST *T);
int Max(BST *T);
int FindMax(int a, int b);
int FindHeightNode(Node **root);
int FindHeight(BST *T);
bool isBSTUtil(Node **root, int min, int max);
bool isBST(BST *T);
void preorderTraversalnode(Node **root);
void preorderTraversal(BST *T);
void inorderTraversalnode(Node **root);
void inorderTraversal(BST *T);
void postorderTraversalnode(Node **root);
void postorderTraversal(BST *T);
int Count_Leaves_Nodes(Node **root);
int Count_Leaves(BST *T);
void FreeAllNodes(Node **root);
void FreeBST(BST *T);
int Count_Nodes_Util(Node **root);
int Count_nodes(BST *T);