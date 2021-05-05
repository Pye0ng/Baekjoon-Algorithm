#include<stdio.h>
int n, m, d[1010], sum[1010];
int max(int a, int b){ return a>b?a:b; }

int main(){
	int i, j;
	scanf("%d", &n);
	for(i=n; i>=1; i--) scanf("%d", &d[i]);
	for(i=1; i<=n; i++){
		sum[i]=d[i];
		for(j=1; j<i; j++)
			if(d[i]>d[j]) sum[i]=max(sum[i], sum[j]+d[i]);
		m=max(m, sum[i]);
	}
	printf("%d", m);
}
