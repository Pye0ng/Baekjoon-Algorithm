#include<stdio.h>
long long int f[1000010], g[1000010];

int main(){
	int n, i, m=1e9+7;
	scanf("%d", &n);
	f[0]=g[1]=1; f[1]=2;
	for(i=2; i<=n; i++){
		g[i]=(f[i-1]+f[i-2]+g[i-2])%m;
		f[i]=(2*g[i]+f[i-2])%m;
	} 
	printf("%lld", f[n]%m);
}
