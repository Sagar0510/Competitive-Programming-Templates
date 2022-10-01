
vector<pair<int,int> > adj[N];

int prims(int n){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    bool visited[n+1]={0};
    visited[1]=1;
    int ans=0;

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
