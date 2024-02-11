#include <iostream>
#include <vector>

using namespace std;

bool isBipartiteUtil(vector<vector<int>>& graph, int src, vector<int>& colorArr, int color) {
    colorArr[src] = color;
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[src][i] && colorArr[i] == -1) {
            if (!isBipartiteUtil(graph, i, colorArr, 1 - color))
                return false;
        }
        else if (graph[src][i] && colorArr[i] == color)
            return false;
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> colorArr(V, -1);
    for (int i = 0; i < V; ++i) {
        if (colorArr[i] == -1) {
            if (!isBipartiteUtil(graph, i, colorArr, 1))
                return false;
        }
    }
    return true;
}

bool canDivideIntoTwoCliques(vector<vector<int>>& graph) {
    // Convert the given graph into its complement graph
    int V = graph.size();
    vector<vector<int>> complementGraph(V, vector<int>(V, 0));
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (i != j)
                complementGraph[i][j] = !graph[i][j];
        }
    }
    
    // Check if the complement graph is bipartite
    return isBipartite(complementGraph);
}

int main() {
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph;
    int n;cin>>n;
    for(int i=0;i<n;i++){
        vector <int> v;
        for(int j=0;j<n;j++){
            int q;cin>>q;
            v.push_back(q);
        }
        graph.push_back(v);
    }

    if (canDivideIntoTwoCliques(graph))
        cout << "Graph can be divided into two cliques.\n";
    else
        cout << "Graph cannot be divided into two cliques.\n";

    return 0;
}
