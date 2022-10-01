
vector<pair<int,int>> adj[N];
vector<int> dist;

void bfs(int s,int n) {
    dist.assign(n + 1, -1);
    deque<int> q;
    dist[s] = 0; q.push_front(s);
    while (q.size()) {
        int u = q.front(); q.pop_front();
        for (auto [v, w] : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + w;
                if (w == 1) q.push_back(v);
                else q.push_front(v);
            }
        }
    }
}

