#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class Graph {
    int V;
    vector<vector<int>> adj; 

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                topologicalSortUtil(neighbor, visited, Stack);
            }
        }
        Stack.push(v);
    }
    void topologicalSort() {
        stack<int> Stack;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, Stack);
            }
        }
        while (!Stack.empty()) {
            cout << Stack.top() << " ";
            Stack.pop();
        }
    }
};

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
    g.topologicalSort();

    return 0;
}
