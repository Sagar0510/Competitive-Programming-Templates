
int n,m;
char ch[N][N]; 
bool visited[N][N];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

bool valid(int x,int y){
  if(x<1||x>n||y<1||y>m) return false;
  if(visited[x][y]) return false;
  return true;
}
 
void dfs(int x,int y) {
    visited[x][y] = 1;
    for(int i=0;i<4;i++){
      if(valid(x+dx[i],y+dy[i])){
        dfs(x+dx[i],y+dy[i]);
      }
    }
}
