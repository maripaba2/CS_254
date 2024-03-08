#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    bool isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack);

public:
    Graph(int V) : V(V), adj(V) {}
    void addEdge(int u, int v);
    bool isCyclic();
};

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

bool Graph::isCyclicUtil(int v, vector<bool>& visited, vector<bool>& recStack) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack))
                return true;
            else if (recStack[neighbor])
                return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool Graph::isCyclic() {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; ++i) {
        if (isCyclicUtil(i, visited, recStack))
            return true;
    }
    return false;
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
    if (g.isCyclic())
        cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle\n";
    return 0;
}
