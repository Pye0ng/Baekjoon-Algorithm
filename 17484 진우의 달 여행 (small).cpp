#include<stdio.h>
#include<algorithm>
using namespace std;
int ans=1e9, l[10][10], c[10][10], r[10][10], d[10][10];

int main(){
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++){
			scanf("%d", &d[i][j]);
			if(i==1) r[i][j]=l[i][j]=c[i][j]=d[i][j];
		}
	for(i=2; i<=n; i++)
		for(j=1; j<=m; j++){
			if(j<m) l[i][j]=d[i][j]+min(r[i-1][j+1], c[i-1][j+1]);
			if(j>1) r[i][j]=d[i][j]+min(l[i-1][j-1], c[i-1][j-1]);
			c[i][j]=d[i][j];
			if(j==1){ c[i][j]+=l[i-1][j]; r[i][j]=1e9; }
			else if(j==m){ c[i][j]+=r[i-1][j]; l[i][j]=1e9; }
			else c[i][j]+=min(l[i-1][j], r[i-1][j]);
		}
	for(i=1; i<=m; i++) ans=min(min(ans, l[n][i]), min(r[n][i], c[n][i]));
	printf("%d", ans);
}
