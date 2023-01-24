#include <bits/stdc++.h>
#define max 1000000000

using namespace std;

vector<int> dijkstra(vector<vector<int>> graph, int start, int end)
{
    vector<int> dist(graph.size(), max);
    vector<int> prev(graph.size(), -1);
    vector<bool> visited(graph.size(), false);
    dist[start] = 0;
    for (int i = 0; i < graph.size(); i++)
    {
        int u = -1;
        for (int j = 0; j < graph.size(); j++)
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) u = j;
        if (dist[u] == max) break;
        visited[u] = true;
        for (int v = 0; v < graph.size(); v++)
            if (graph[u][v] != 0)
                if (dist[v] > dist[u] + graph[u][v])
                {
                    dist[v] = dist[u] + graph[u][v];
                    prev[v] = u;
                }
    }
    vector<int> path;
    for (int v = end; v != -1; v = prev[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    int start, end;
    cin >> start >> end;
    vector<int> path = dijkstra(graph, start, end);
    for (int i = 0; i < path.size(); i++) cout << path[i] << " ";
    return 0;
}

// Path: Dijkstra.cpp