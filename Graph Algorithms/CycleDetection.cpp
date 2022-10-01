
vector<int> adj[N];
bool visited[N];

bool dfs(int u,int p) {
    visited[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v])
           {if(dfs(v,u)) return true;}
        else if(v!=p) return true;  
    }
    return false;
}