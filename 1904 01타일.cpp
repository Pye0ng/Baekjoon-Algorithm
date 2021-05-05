#include<stdio.h>
#define M 15746
int n, d[1000010];

int main(){
	int i;
	scanf("%d", &n);
	d[0]=d[1]=1;
	for(i=2; i<=n; i++) d[i]=(d[i-1]+d[i-2])%M;
	printf("%d", d[n]);
} 
