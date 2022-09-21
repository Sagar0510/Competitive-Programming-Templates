ll n,m;
char ch[N][N]; 
bool visited[N][N];
ll dx[]={-1,0,1,0};
ll dy[]={0,1,0,-1};
 
bool valid(ll x,ll y){
  if(x<1||x>n||y<1||y>m) return false;
  if(visited[x][y]) return false;
  return true;
}
 
void dfs(ll x,ll y) {
    visited[x][y] = 1;
    rep(i,0,4){
      if(valid(x+dx[i],y+dy[i])){
        dfs(x+dx[i],y+dy[i]);
      }
    }
}
