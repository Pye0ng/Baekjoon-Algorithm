#include<stdio.h>
#include<memory.h>
int n, m, cnt;
bool map[60][60], visited[60][60];

int dx[]={-1, 0, 0, 1, -1, -1, 1, 1};
int dy[]={0, -1, 1, 0, -1, 1, -1, 1};

void dfs(int x, int y){
	visited[x][y]=1;
	for(int i=0; i<8; i++){
		int ax=x+dx[i];
		int ay=y+dy[i];
		if(ax<0||ay<0||ax>=m||ay>=n) continue;
		if(map[ax][ay]&&!visited[ax][ay]) dfs(ax, ay);
	}
}

int main(){
	int i, j;
	while(true){
		scanf("%d %d", &n, &m);
		if(n==0&&m==0) return 0;
		cnt=0;
		memset(visited, 0, sizeof(visited));
		for(i=0; i<m; i++)
			for(j=0; j<n; j++) scanf("%d", &map[i][j]);
		for(i=0; i<m; i++)
			for(j=0; j<n; j++)
				if(map[i][j]&&!visited[i][j]){
					dfs(i, j);	
					cnt++;	
				}
		printf("%d\n", cnt);
	}
}
