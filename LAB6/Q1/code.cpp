#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int> >& adj,int V)
{

	vector<int> indegree(V);
	for (int i = 0; i < V; i++) {
		for (auto it : adj[i]) {
			indegree[it]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < V; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	vector<int> result;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		result.push_back(node);
	
		for (auto it : adj[node]) {
			indegree[it]--;
		
			if (indegree[it] == 0)
				q.push(it);
		}
	}
	if (result.size() != V) {
		cout << "Graph contains cycle!" << endl;
		return {};
	}

	return result;
}

int main()
{
	int n = 4;
	vector<vector<int> > edges
		= { { 0, 1 }, { 1, 2 }, { 3, 1 }, { 3, 2 } };
	vector<vector<int> > adj(n);


	for (auto i : edges) {
		adj[i[0]].push_back(i[1]);
	}

	cout << "Topological sorting of the graph: ";
	vector<int> result = topologicalSort(adj, n);


	for (auto i : result) {
		cout << i << " ";
	}

	return 0;
}
