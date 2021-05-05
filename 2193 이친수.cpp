#include<stdio.h>
long long int n, a[95];

int main(){
	int i;
	scanf("%d", &n);
	a[1]=1; 
	for(i=2; i<=n; i++) a[i]=a[i-1]+a[i-2];
	printf("%lld", a[n]);
}
