vll adj[N];
bool visited[N];

void dfs(ll u) {
    visited[u] = 1;
    for (ll v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}
