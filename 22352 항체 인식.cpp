#include<stdio.h>
int n, m, p, q, b, cnt, ch, a[32][32], d[32][32], v[32][32];
int dx[]={-1, 1, 0, 0};
int dy[]={0, 0, -1, 1};

void find(int x, int y){
	int nx, ny, i;
	if(v[x][y]) return;
	v[x][y]=1;
	for(i=0; i<4; i++){
		nx=x+dx[i]; ny=y+dy[i];
		if(nx<1||nx>n||ny<1||ny>m) continue;
		if(d[nx][ny]==0&&a[nx][ny]==a[x][y]) ch=1;
		if(d[nx][ny]&&!v[nx][ny]) find(nx, ny);
	}
}

int main(){
	int i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++) scanf("%d", &a[i][j]);
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++){
			scanf("%d", &b);
			if(a[i][j]!=b){
				d[i][j]=1;
				if(p==0){ p=a[i][j]; q=b; }
				else if(p!=a[i][j]||q!=b){
					printf("NO");
					return 0;
				} 
			}
		}
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++)
			if(d[i][j]&&v[i][j]==0){ find(i, j); cnt++; }
	if(cnt>1||ch==1) printf("NO");
	else printf("YES"); 
}
