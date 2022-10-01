
int n,m;
char matrix[N][N]; 
bool visited[N][N];
int dist[N][N];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
 
bool valid(int x,int y){
  if(x<1||x>n||y<1||y>m) return false;
  if(visited[x][y]) return false;
  return true;
}
 
void bfs(int x,int y) {
    queue<pair<int,int>> q;
    visited[x][y]=1;
    dist[x][y] = 0; q.push({x,y});
    while (q.size()) {
        int xx = q.front().ff;
        int yy = q.front().ss;
        q.pop();
        
        rep(i,0,4) {
          if(valid(xx+dx[i],yy+dy[i])){
             visited[xx+dx[i]][yy+dy[i]]=1;
             dist[xx+dx[i]][yy+dy[i]]=dist[xx][yy]+1;
             q.push({xx+dx[i],yy+dy[i]});
          }
        }
    }
}
 