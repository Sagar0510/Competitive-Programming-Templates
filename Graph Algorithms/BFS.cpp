
vector<int> adj[N], dist(N,-1);

void bfs(int s) {
    queue<int> q;
    dist[s] = 0; q.push(s);
    while (q.size()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}