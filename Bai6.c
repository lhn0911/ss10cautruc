#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct Graph
{
    int vertices;
    int matrix[MAX][MAX];
} Graph;

void initializeGraph(Graph *graph, int vertices)
{
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph->matrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *graph, int start, int end, bool isDirected)
{
    graph->matrix[start][end] = 1;
    if (!isDirected)
    {
        graph->matrix[end][start] = 1;
    }
}

void displayGraph(Graph *graph)
{
    printf("Ma tran ke cua do thi:\n");
    for (int i = 0; i < graph->vertices; i++)
    {
        for (int j = 0; j < graph->vertices; j++)
        {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

void dfsRecursive(Graph *graph, int vertex, bool visited[])
{
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < graph->vertices; i++)
    {
        if (graph->matrix[vertex][i] == 1 && !visited[i])
        {
            dfsRecursive(graph, i, visited);
        }
    }
}

void DFS(Graph *graph, int startVertex)
{
    bool visited[MAX] = {false};
    printf("DFS bat dau tu dinh %d: ", startVertex);
    dfsRecursive(graph, startVertex, visited);
    printf("\n");
}

void BFS(Graph *graph, int startVertex)
{
    bool visited[MAX] = {false};
    int queue[MAX];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("BFS bat dau tu dinh %d: ", startVertex);
    while (front < rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->vertices; i++)
        {
            if (graph->matrix[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main()
{
    int vertices = 5;
    Graph graph;

    initializeGraph(&graph, vertices);

    addEdge(&graph, 0, 1, false);
    addEdge(&graph, 0, 2, false);
    addEdge(&graph, 1, 2, false);
    addEdge(&graph, 1, 3, false);
    addEdge(&graph, 3, 4, false);

    displayGraph(&graph);

    DFS(&graph, 0);
    BFS(&graph, 0);

    return 0;
}
