#include<stdio.h>
#include<memory.h>
long long int d[33][33];

long long int d2(int n, int k){
	if(d[n][k]) return d[n][k];
	if(n==0) return 1;
	d[n][k]=d2(n-1, k+1);
	if(k>0) d[n][k]+=d2(n, k-1);
	return d[n][k];
}

int main(){
	int n;
	scanf("%d", &n);
	while(n!=0){
		d2(n, 0);
		printf("%lld\n", d2(n, 0));
		scanf("%d", &n);
		memset(d, 0, sizeof(d));
	}
}
