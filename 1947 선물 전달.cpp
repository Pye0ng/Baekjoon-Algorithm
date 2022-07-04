#include<stdio.h>
typedef long long ll;
ll m=1e9, d[1000100];

int main(){
	int n, i;
	scanf("%d", &n); d[2]=1; d[3]=2;
	for(i=4; i<=n; i++) d[i]=(d[i-1]*i)%m+(i%2?-1:1);
	printf("%lld", d[n]);
}
