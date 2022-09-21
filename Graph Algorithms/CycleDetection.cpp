
vll adj[N];
bool visited[N];

bool dfs(ll u,ll p) {
    visited[u] = 1;
    for (ll v : adj[u]) {
        if (!visited[v])
           {if(dfs(v,u)) return true;}
        else if(v!=p) return true;  
    }
    return false;
}
