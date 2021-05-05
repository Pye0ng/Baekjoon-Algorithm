#include<stdio.h>
unsigned long long int f[10001];

int main(){
	int n, p, q, i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d %d", &p, &q);
		f[1]=1%q; f[2]=1%q;
		for(j=3; j<=p; j++) f[j]=f[j-1]%q+f[j-2]%q;
		printf("Case #%lld: %lld\n", i, f[p]%q);
	}
}
