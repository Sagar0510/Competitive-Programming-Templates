
vector<int> adj[N];
bool visited[N];

void dfs(int u) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}