#include<stdio.h>
#include<memory.h>
int a[110][110];
bool b[110][110], visited[110][110];
int n, p, cnt, max, min=100;

int dx[]={-1, 0, 0, 1};
int dy[]={0, 1, -1, 0};

void dfs(int x, int y){
	visited[x][y]=1;
	for(int i=0; i<4; i++){
		int ax=x+dx[i];
		int ay=y+dy[i];
		if(ax<0||ay<0||ax>=n||ay>=n) continue;
		if(b[ax][ay]&&!visited[ax][ay]) dfs(ax, ay);
	}
}

int main(){
	int i, j;
	scanf("%d", &n);
	for(i=0; i<n; i++)
		for(j=0; j<n; j++){
			scanf("%d", &a[i][j]);
			if(a[i][j]>max) max=a[i][j];
			if(a[i][j]<min) min=a[i][j];
		}
	for(int k=min-1; k<max; k++){
		memset(b, 0, sizeof(b));
		memset(visited, 0, sizeof(visited));
		cnt=0;
		for(i=0; i<n; i++)
			for(j=0; j<n; j++) b[i][j]=(a[i][j]>k);
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(b[i][j]==1&&visited[i][j]==0){
					cnt++;
					dfs(i, j);
				}
			}
		}
		if(cnt>p) p=cnt;
	}
	printf("%d", p);
}
