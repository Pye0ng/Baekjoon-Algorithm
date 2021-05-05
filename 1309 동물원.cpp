#include<stdio.h>
int m=9901, a[100010], b[100010];

int main(){
	int n, i;
	scanf("%d", &n);
	a[1]=1; b[1]=2;
	for(i=2; i<=n; i++){
		a[i]+=(a[i-1]+b[i-1])%m;
		b[i]+=(2*a[i-1]+b[i-1])%m;
	}
	printf("%d", (a[n]+b[n])%m);
}
