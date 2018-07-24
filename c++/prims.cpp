#include <iostream>
#include <climits>

#define V 5

using namespace std;


int minKey(int *key, bool *in_set)
{
  int min = INT_MAX;
  int min_index;

  for(int i = 0; i < V; i++)
  {
    if(in_set[i] == false && key[i] < min)
    {
      min = key[i];
      min_index = i;
    }
  }

  return min_index;
}

void printMST(int parent[], int size, int graph[V][V])
{
  for(int i = 1; i < V; i++)
  {
    cout << parent[i] << " ---> " << i << "    : " << graph[i][parent[i]] << endl;
  }
}


void primMST(int graph[V][V])
{
  int parent[V];
  int key[V];
  bool in_set[V];

  for(int i = 0; i < V; i++)
  {
    key[i] = INT_MAX;
    in_set[i] = false;
  }

  key[0] = 0;
  parent[0] = -1;

  for(int i = 0; i < V - 1; i++)
  {
    int u = minKey(key, in_set);

    in_set[u] = true;

    for(int v = 0; v < V; v++)
    {
      if(graph[u][v] && in_set[v] == false && graph[u][v] < key[v])
      {
        parent[v] = u;
        key[v] = graph[u][v];
      }
    }
  }

  printMST(parent, V, graph);
}

int main()
{
  int graph[V][V] = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0},
  };

  primMST(graph);
  return 0;
}
