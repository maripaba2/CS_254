#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> adj[100005], revAdj[100005];
bool visited[100005];
stack<int> order;
vector<int> component;

void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs1(v);
    }
    order.push(u);
}

void dfs2(int u) {
    visited[u] = true;
    component.push_back(u);
    for (int v : revAdj[u]) {
        if (!visited[v])
            dfs2(v);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        revAdj[v].push_back(u);
    }
    fill(visited, visited + N + 1, false);

    for (int i = 1; i <= N; ++i) {
        if (!visited[i])
            dfs1(i);
    }

    fill(visited, visited + N + 1, false);
    while (!order.empty()) {
        int u = order.top();
        order.pop();
        if (!visited[u]) {
            dfs2(u);
            // Output the strongly connected component
            for (int node : component)
                cout << node << " ";
            cout << endl;
            component.clear();
        }
    }
    return 0;
}
