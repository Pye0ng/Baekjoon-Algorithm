#include<stdio.h>
typedef long long int ll;
ll d[33340];

int main(){
	int n, m=1000000009, i;
	d[2]=2;
	scanf("%d", &n);
	for(i=3; i<=n; i++) d[i]=d[i-1]*3%m;
	printf("%lld", d[n]%m);
}
