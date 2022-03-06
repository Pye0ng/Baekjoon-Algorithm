#include<stdio.h>
int f[3000100];

int main(){
	long long int N;
	int n, p=1500000, i;
	scanf("%lld", &N);
	n=N%p; f[1]=1;
	for(i=2; i<=n; i++) f[i]=(f[i-1]+f[i-2])%1000000;
	printf("%d", f[n]);
}
