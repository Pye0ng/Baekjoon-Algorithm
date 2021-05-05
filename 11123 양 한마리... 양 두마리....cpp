#include<stdio.h>
#include<memory.h>
bool visit[110][110];
char s[110][110];
int n, m, N, cnt;

int dx[]={-1, 0, 0, 1};
int dy[]={0, 1, -1, 0};

void dfs(int x, int y){
	visit[x][y]=1;
	for(int i=0; i<4; i++){
		int ax=x+dx[i];
		int ay=y+dy[i];
		if(ax<0||ay<0||ax>=n||ay>=m) continue;
		if(s[ax][ay]!='#'||visit[ax][ay]) continue;
		dfs(ax, ay);
	}
}

int main(){
	int i, j;
	scanf("%d", &N);
	while(N--){
		memset(s, 0, sizeof(s));
		memset(visit, 0, sizeof(visit));
		cnt=0;
		scanf("%d %d", &n, &m);
		for(i=0; i<n; i++) scanf("%s", s[i]);
		for(i=0; i<n; i++){
			for(j=0; j<m; j++){
				if(s[i][j]=='#'&&!visit[i][j]){
					cnt++;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}
}
