#include<stdio.h>
int n, m, mx, sum, cnt;
bool map[510][510], visited[510][510];

int dx[]={1, 0, 0, -1};
int dy[]={0, -1, 1, 0};

void dfs(int x, int y){
	visited[x][y]=1;
	sum++;
	for(int i=0; i<4; i++){
		int ax=x+dx[i];
		int ay=y+dy[i];
		if(ax<=0||ay<=0||ax>n||ay>m) continue;
		if(!visited[ax][ay]&&map[ax][ay]) dfs(ax, ay);
	}
}

int main(){
	int i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++) scanf("%d", &map[i][j]);
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			sum=0;
			if(map[i][j]&&!visited[i][j]){
				cnt++;
				dfs(i, j);
				if(sum>mx) mx=sum;
			}
		}
	}
	printf("%d\n%d", cnt, mx);
}
