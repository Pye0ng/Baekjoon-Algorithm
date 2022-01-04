#include<stdio.h>
int cnt, s[110], d[110][110];

void ch(int x, int y, int t){
	if(t==-1||t==0) return;
	for(int i=x-1; i<=x+1; i++)
		for(int j=y-1; j<=y+1; j++)
			if(t==d[i][j]&&s[t]==0&&!(i==x&&j==y)){ s[t]=1; cnt++; return; }
	
}

int main(){
	int t, m, n, i, j;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		for(i=1; i<=n; i++)
			for(j=1; j<=m; j++) scanf("%d", &d[i][j]);
		for(i=1; i<=n; i++)
			for(j=1; j<=m; j++){ ch(i, j, d[i][j]); }
		for(i=1; i<=n; i++)
			for(j=1; j<=m; j++) d[i][j]=0; 
		for(i=1; i<=100; i++) s[i]=0;
		printf("%d\n", cnt); cnt=0;
	}
}
