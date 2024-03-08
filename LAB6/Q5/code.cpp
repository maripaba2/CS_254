#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    int time;

    void APUtil(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<bool>& ap);
    void bridgeUtil(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent);

public:
    Graph(int V) : V(V), adj(V), time(0) {}
    void addEdge(int u, int v);
    void findArticulationPoints();
    void findBridges();
};

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

void Graph::APUtil(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<bool>& ap) {
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap);
            low[u] = min(low[u], low[v]);
            if (parent[u] == -1 && children > 1)
                ap[u] = true;
            if (parent[u] != -1 && low[v] >= disc[u])
                ap[u] = true;
        }
        else if (v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
}


void Graph::findArticulationPoints() {
    vector<bool> visited(V, false);
    vector<int> disc(V);
    vector<int> low(V);
    vector<int> parent(V, -1);
    vector<bool> ap(V, false);

    for (int i = 0; i < V; ++i)
        if (!visited[i])
            APUtil(i, visited, disc, low, parent, ap);

    cout << "Articulation Points: ";
    for (int i = 0; i < V; ++i)
        if (ap[i])
            cout << i << " ";
    cout << endl;
}

void Graph::findBridges() {
    vector<bool> visited(V, false);
    vector<int> disc(V);
    vector<int> low(V);
    vector<int> parent(V, -1);
    
}


int main() {
    cout<<"No. of nodes : ";
    int n;cin>>n;
    Graph g(n);
    cout<<"No. of edges : ";
    int m;cin>>m;
    for(int i=0;i<m;i++){
        ll x,y;cin>>x>>y;
        g.addEdge(x,y);
    }
    g.findArticulationPoints();

    return 0;
}
