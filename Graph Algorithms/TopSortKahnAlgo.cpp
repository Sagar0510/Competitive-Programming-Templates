
vector<int> adj[N];
bool visited[N];
int IN[N];
vector<int> topsort;

bool kahn(int &n){
    queue<int> q;
    rep(i,1,n+1){
        if(IN[i]==0) q.push(i),topsort.pb(i);
  }
  while(!q.empty()){
    int x=q.front();
    q.pop();
    for(auto y:adj[x]){
        IN[y]--;
        if(IN[y]==0) q.push(y),topsort.pb(y);
    }
  }
  return (topsort.size()==n);
}

