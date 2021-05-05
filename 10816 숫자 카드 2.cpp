#include<stdio.h>
int a[20000001];

int main(){
	int n, m, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &m);
		a[m+10000000]++;
	}
	scanf("%d", &m);
	for(i=1; i<=m; i++){
		scanf("%d", &n);
		printf("%d ", a[n+10000000]);
	}
}
