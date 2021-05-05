#include<stdio.h>
int n, m, k, sum, max;
bool trash[120][120], visited[120][120];

int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};

void dfs(int x, int y){
	visited[x][y]=1;
	sum++;
	for(int i=0; i<4; i++){
		int ax=x+dx[i];
		int ay=y+dy[i];
		if(ax<=0||ay<=0||ax>n||ay>m) continue;
		if(!visited[ax][ay]&&trash[ax][ay]) dfs(ax, ay);
	}
}

int main(){
	int i, j;
	scanf("%d %d %d", &n, &m, &k);
	for(i=1; i<=k; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		trash[x][y]=1;
	}
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++){
			sum=0;
			if(trash[i][j]&&!visited[i][j]){
				dfs(i, j);
				if(sum>max) max=sum;
			}
		}
	printf("%d", max);
}
