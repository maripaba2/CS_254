#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[100005];
int dp[100005];

int dfs(int u) {
    if (dp[u] != -1)
        return dp[u];
    int mx = 0;
    for (int v : adj[u])
        mx = max(mx, dfs(v) + 1);
    return dp[u] = mx;
}

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    fill(dp, dp + N + 1, -1);
    int longestPath = 0;
    for (int i = 1; i <= N; ++i)
        longestPath = max(longestPath, dfs(i));
    cout << longestPath << endl;
    return 0;
}

