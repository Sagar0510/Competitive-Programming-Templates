vpl adj[N];

ll prims(ll n){
    priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>, greater<pair<ll,pair<ll,ll>>>> pq;
    bool visited[n+1]={0};
    visited[1]=1;
    ll ans=0;

    for(auto x:adj[1]) pq.push({x.ss,{x.ff,1}});

    while(pq.size()){
        auto x = pq.top(); pq.pop();
        if(visited[x.ss.ff]) continue;
        visited[x.ss.ff]=1;
        // cout<<"["<<x.ss.ff<<"-"<<x.ss.ss<<"@"<<x.ff<<"]\n";
        ans+=x.ff;
        for(auto y:adj[x.ss.ff])
            pq.push({y.ss,{y.ff,x.ss.ff}});
    }

    rep(i,1,n+1)
        if(!visited[i])
            return -1;
    return ans;
}
