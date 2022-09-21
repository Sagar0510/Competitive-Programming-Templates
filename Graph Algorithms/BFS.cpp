vll adj[N], dist(N,-1);

void bfs(ll s) {
    queue<ll> q;
    dist[s] = 0; q.push(s);
    while (q.size()) {
        ll u = q.front(); q.pop();
        for (ll v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
