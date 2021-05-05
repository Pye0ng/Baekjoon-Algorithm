#include<stdio.h>
int n;
long long int d[82];

int main(){
	d[1]=d[2]=1;
	scanf("%d", &n);
	for(int i=3; i<=n+1; i++) d[i]=d[i-1]+d[i-2];
	printf("%lld", 2*(d[n+1]+d[n]));
}
