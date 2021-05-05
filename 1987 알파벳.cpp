#include<stdio.h>
int n, m, ans;
char c[25][25];

int dx[]={-1, 0, 0, 1};
int dy[]={0, 1, -1, 0};

void find(int x, int y, int cnt, bool visit[]){
	cnt++; if(cnt>ans) ans=cnt;
	int nx, ny, i;
	for(i=0; i<4; i++){
		nx=x+dx[i]; ny=y+dy[i];
		if(!visit[c[nx][ny]-'A']&&nx>=0&&ny>=0&&nx<n&&ny<m){
			visit[c[nx][ny]-'A']=1;
			find(nx, ny, cnt, visit);
			visit[c[nx][ny]-'A']=0;
		}
	}
}

int main(){
	int i;
	bool visit[30];
	for(i=0; i<29; i++) visit[i]=0;
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++) scanf("%s", c[i]);
	visit[c[0][0]-'A']=1;
	find(0, 0, 0, visit);
	printf("%d", ans);
}
