#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Graph
{
    int NumVertices;
    bool **edges;
} Graph;

Graph *InitGraph(int NumVertices)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    if (g == NULL)
    {
        return NULL;
    }
    g->NumVertices = NumVertices;
    g->edges = calloc(sizeof(bool *), g->NumVertices);
    if (g->edges == NULL)
    {
        free(g);
        return NULL;
    }
    for (int i = 0; i < NumVertices; i++)
    {
        g->edges[i] = calloc(sizeof(bool), g->NumVertices);
        if (g->edges[i] == NULL)
        {
            FreeGraph(g);
            return NULL;
        }
    }
    return g;
}

void FreeGraph(Graph *g)
{
    if (g->edges == NULL)
    {
        free(g);
        return;
    }
    for (int i = 0; i < g->NumVertices; i++)
    {
        if (g->edges[i] != NULL)
        {
            free(g->edges[i]);
        }
    }
    free(g->edges);
}

bool has_edge(Graph *g, unsigned int from_node, unsigned int to_node)
{
    return g->edges[from_node][to_node];
}

bool add_edge(Graph *g, unsigned int from_node, unsigned int to_node)
{
    if (has_edge(g, from_node, to_node))
    {
        return false;
    }
    g->edges[from_node][to_node] = true;
    return true;
}

bool Dotwrite(Graph *g, const char *path)
{
    FILE *file = fopen(path, "w");
    if (!file)
    {
        fprintf(stderr, "Cannot open file to write");
        return false;
    }
    fprintf(file, "digraph {\n");
    for (int i = 0; i < g->NumVertices; i++)
    {
        for (int j = 0; j < g->NumVertices; j++)
        {
            if (g->edges[i][j])
            {
                fprintf(file, "%d -> %d;\n", i, j);
            }
        }
    }
    fprintf(file, "}\n");
    fclose(file);
    return true;
}

int main()
{
    Graph *g1 = InitGraph(10);
    add_edge(g1, 0, 1);
    add_edge(g1, 0, 2);
    add_edge(g1, 0, 0);
    add_edge(g1, 1, 5);
    add_edge(g1, 1, 2);
    add_edge(g1, 1, 3);
    add_edge(g1, 5, 4);
    add_edge(g1, 5, 3);
    if (!Dotwrite(g1, "test.dot"))
    {
        printf("Error");
    }
    system("dot -Tpng -O test.dot");
    FreeGraph(g1);
    system("pause");
    return 0;
}