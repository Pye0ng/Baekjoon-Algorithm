#include<stdio.h>
int m=1e9+9, d[50010];

int main(){
	int n, i;
	scanf("%d", &n);
	d[1]=d[2]=1; d[3]=2;
	for(i=4; i<=n; i++) d[i]=(d[i-1]+d[i-3])%m;
	printf("%d", d[n]);
}
