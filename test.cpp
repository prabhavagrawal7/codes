#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
private:
    int vertices;
    vector<vector<int>> adj;

public:
    Graph(int V) : vertices(V), adj(V) {}

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    bool isCyclicUtil(int v, vector<bool> &visited, vector<int> &parent, int k)
    {
        visited[v] = true;

        for (int u : adj[v])
        {
            if (!visited[u])
            {
                parent[u] = v;
                if (isCyclicUtil(u, visited, parent, k))
                {
                    return true;
                }
            }
            else if (u != parent[v] && k == 2)
            {
                return true;
            }
        }
        return false;
    }

    bool hasCycleOfSizeK(int k)
    {
        vector<bool> visited(vertices, false);
        vector<int> parent(vertices, -1);

        for (int v = 0; v < vertices; ++v)
        {
            if (!visited[v] && isCyclicUtil(v, visited, parent, k))
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int V, E, k;
    cin >> V >> E; // Number of vertices and edges
    Graph g(V + 1);

    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "Enter the size of the cycle to detect (k): ";
    cin >> k;

    if (g.hasCycleOfSizeK(k))
    {
        cout << "The graph contains a cycle of size " << k << ".\n";
    }
    else
    {
        cout << "The graph does not contain a cycle of size " << k << ".\n";
    }

    return 0;
}
