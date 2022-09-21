vector<pair<ll,ll>> adj[N];
vector<ll> dist;

void bfs(ll s,ll n) {
    dist.assign(n + 1, -1);
    deque<ll> q;
    dist[s] = 0; q.push_front(s);
    while (q.size()) {
        ll u = q.front(); q.pop_front();
        for (auto [v, w] : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + w;
                if (w == 1) q.push_back(v);
                else q.push_front(v);
            }
        }
    }
}


