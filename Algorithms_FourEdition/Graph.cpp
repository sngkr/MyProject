#include <iostream>
#include <vector>
#include<unordered_set>

using namespace std;

class Graph
{
private:
    int V;
    int E;
    vector<vector<int>> adj;

public:
    Graph(int V1)
    {
        V = V1;
    }

    int V() { return V; }
    int E() { return E; }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
        E++;
    }

    vector<int> adj(int v)
    {
        return adj[v];
    }
};