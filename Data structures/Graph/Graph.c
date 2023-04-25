#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int adjVertexIndex;
    int weight;
    struct Node *next;
    bool *marks;
} Node;

typedef struct Graph
{
    int numVertices;
    struct Node **adjLists;
} Graph;

// Create a node
Node *createNode(int v)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->adjVertexIndex = v;
    newNode->next = NULL;
    newNode->weight = NULL;
    newNode->marks = NULL;
    return newNode;
}

// Create a graph
Graph *createAGraph(int vertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node *));

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Add edge
void addEdge(Graph *graph, int s, int d)
{
    // Add edge from s to d
    Node *newNode = createNode(d);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;

    // Add edge from d to s
    newNode = createNode(s);
    newNode->next = graph->adjLists[d];
    graph->adjLists[d] = newNode;
}

// Print the graph
void printGraph(Graph *graph)
{
    for (int v = 0; v < graph->numVertices; v++)
    {
        Node *temp = graph->adjLists[v];
        printf("\n Vertex %d\n: ", v);
        while (temp)
        {
            printf("%d -> ", temp->adjVertexIndex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    Graph *graph = createAGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);
    printGraph(graph);
    system("pause");
    return 0;
}