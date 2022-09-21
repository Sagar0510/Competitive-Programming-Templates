vll adj[N];
bool visited[N];
ll IN[N];
vll topsort;

bool kahn(ll &n){
	queue<ll> q;
	rep(i,1,n+1){
		if(IN[i]==0) q.push(i),topsort.pb(i);
  }
  while(!q.empty()){
  	ll x=q.front();
  	q.pop();
  	for(auto y:adj[x]){
  		IN[y]--;
  		if(IN[y]==0) q.push(y),topsort.pb(y);
  	}
  }
  return (topsort.size()==n);
}

