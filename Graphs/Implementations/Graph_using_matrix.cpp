#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>> matrix;

public:
    Graph(int v)
    {
        V = v;
        matrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v)
    {
        matrix[u][v] = 1;
        matrix[v][u] = 1; // undirected
    }

    void print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " : ";
            for (int j = 0; j < V; j++)
            {
                if (matrix[i][j] == 1)
                    cout << j << " ";
            }
            cout << "\n";
        }
    }

    void BFS()
    {
        queue<int> q;
        vector<bool> visited(V, false);

        q.push(0);
        visited[0] = true;

        while (q.size() > 0)
        {
            int u = q.front();
            q.pop();

            cout << u << " ";

            for (int j = 0; j < V; j++)
            {
                if (matrix[u][j] == 1 && !visited[j])
                {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }
};

int main()
{
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 5);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.print();

    g.BFS();

    return 0;
}