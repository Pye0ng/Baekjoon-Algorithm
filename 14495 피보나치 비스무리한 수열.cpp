#include<stdio.h>
long long int n, d[118];

int main(){
	scanf("%d", &n);
	d[1]=d[2]=d[3]=1;
	for(int i=4; i<=n; i++) d[i]=d[i-1]+d[i-3];
	printf("%lld", d[n]);
}
