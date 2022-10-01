
vector<int> adj[N];
bool visited[N];
int col[N];

bool dfs(int u,int c) {
    visited[u] = 1;
    col[u] = c;
    for (int v : adj[u]) {
        if (!visited[v])
           {if(!dfs(v,c^1)) return false;}
        else if(col[v]==col[u]) return false;  
    }
    return true;
}

