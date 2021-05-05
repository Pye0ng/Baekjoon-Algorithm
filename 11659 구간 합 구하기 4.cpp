#include<stdio.h>
int d[100010];

int main(){
	int n, m, x, y, i;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", &d[i]);
		d[i]+=d[i-1];
	}
	for(i=1; i<=m; i++){
		scanf("%d %d", &x, &y);
		printf("%d\n", d[y]-d[x-1]);
	}
}
