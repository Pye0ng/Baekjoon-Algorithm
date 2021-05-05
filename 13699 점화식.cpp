#include<stdio.h>
long long int t[40];

int main(){
	int n, i, j;
	scanf("%d", &n);
	t[0]=t[1]=1;
	for(i=2; i<=n; i++)
		for(j=0; j<i; j++) t[i]+=t[j]*t[i-j-1];
	printf("%lld", t[n]);
}
