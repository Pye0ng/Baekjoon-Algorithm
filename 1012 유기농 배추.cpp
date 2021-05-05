#include<stdio.h>
#include<memory.h>

int n, m, k;
int visited[60][60], a[60][60];
int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};

void find(int x, int y){
	visited[x][y]=1; 
	for(int i=0; i<4; i++){
		int ax=x+dx[i];
		int ay=y+dy[i];
		if(ax<0||ay<0||ay>=n||ax>=m) continue;
		if(a[ax][ay]==0||visited[ax][ay]==1) continue;
		find(ax, ay);
	}
}

int main(){
	int N, i, j;
	scanf("%d", &N);
	while(N--){
		scanf("%d %d %d", &n, &m, &k);
		for(i=1; i<=k; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			a[y][x]=1;
		}
		int cnt=0;
		for(i=0; i<m; i++){
			for(j=0; j<n; j++){
				if(a[i][j]==1&&visited[i][j]==0){
					find(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));
	}
}
