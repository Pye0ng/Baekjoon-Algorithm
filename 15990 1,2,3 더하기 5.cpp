#include<stdio.h>
long long int a[100010], b[100010], c[100010];

int main(){
	int t, n, m=1e9+9, i;
	scanf("%d", &t);
	a[1]=b[2]=a[3]=b[3]=c[3]=1; 
	while(t--){
		scanf("%d", &n);
		for(i=4; i<=n; i++){
			a[i]=(b[i-1]+c[i-1])%m;
			b[i]=(a[i-2]+c[i-2])%m;
			c[i]=(a[i-3]+b[i-3])%m;
		}
		printf("%lld\n", ((a[n]+b[n])%m+c[n])%m);
	}
}
