
vll adj[N];
bool visited[N];
ll col[N];

bool dfs(ll u,ll c) {
    visited[u] = 1;
    col[u] = c;
    for (ll v : adj[u]) {
        if (!visited[v])
           {if(!dfs(v,c^1)) return false;}
        else if(col[v]==col[u]) return false;  
    }
    return true;
}


