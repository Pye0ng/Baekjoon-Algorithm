#include<stdio.h>
int max(int a, int b){ return a>b?a:b; }
int m, d[1010], sum[1010];

int main(){
	int n, i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	for(i=1; i<=n; i++){
		sum[i]=d[i];
		for(j=1; j<i; j++)
			if(d[i]>d[j]) sum[i]=max(sum[i], d[i]+sum[j]);
		m=max(m, sum[i]);
	}
	printf("%d", m);
}
