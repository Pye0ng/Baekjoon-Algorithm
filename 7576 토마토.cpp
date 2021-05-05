#include<stdio.h>
#include<queue>
using namespace std;
queue<pair<int, int> > q;
int n, m, t=-1, ch=1;
int d[1010][1010], visited[1010][1010];
int dx[]={-1, 0, 1, 0};
int dy[]={0, 1, 0, -1};

int main(){
	int x, y, nx, ny, s, i, j;
	scanf("%d %d", &m, &n);
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++){
			scanf("%d", &d[i][j]);
			if(d[i][j]==1){ q.push({i, j}); visited[i][j]=1; }
			if(d[i][j]==-1) visited[i][j]=1;
			if(d[i][j]==0) ch=0;
		}
	if(ch){ printf("0"); return 0; }
	while(!q.empty()){
		s=q.size();
		for(i=0; i<s; i++){
			x=q.front().first; y=q.front().second; q.pop(); 
			for(j=0; j<4; j++){
				nx=x+dx[j]; ny=y+dy[j];
				if(nx<=n&&nx>0&&ny<=m&&ny>0&&visited[nx][ny]==0&&d[nx][ny]==0){
					q.push({nx, ny});
					visited[nx][ny]=1;
				}
			}
		}
		t++;
	}
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			if(!visited[i][j]){ printf("-1"); return 0; }
	printf("%d", t);
}
