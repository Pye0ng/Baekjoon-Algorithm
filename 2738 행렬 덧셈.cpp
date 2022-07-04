#include<stdio.h>
int c[110][110];

int main(){
	int n, m, t, i, j;
	scanf("%d %d",&n, &m);
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++) scanf("%d", &c[i][j]);
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++){
			scanf("%d", &t);
			c[i][j]+=t;
		}
	for(i=1; i<=n; i++){
		for(j=1; j<=m; j++) printf("%d ", c[i][j]);
		printf("\n");
	}
}
