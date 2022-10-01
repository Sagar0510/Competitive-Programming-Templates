
vector<int> adj[N];
bool visited[N];
int inn[N],low[N],timer;

void dfs(int u, int p) {
    visited[u] = 1;
    inn[u]=low[u]=timer++; 
    int child=0;
    for (int v : adj[u]) {
        if (v==p) continue;
        if (visited[v]) low[u]=min(low[u],inn[v]);
        else{
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            child++;
            if(low[v]>inn[u])
            // u -- v is a bridge;
            if(low[v]>=inn[u] and p!=-1)
            // u is an articulation point
        }
    }
    if(p==-1 and child>1)
    // u is an articulation point  
}

