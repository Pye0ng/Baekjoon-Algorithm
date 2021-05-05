#include<stdio.h>
int t, n;
long long int d[110];

int main(){
	int i;
	d[1]=d[2]=1;
	for(i=3; i<=100; i++) d[i]=d[i-2]+d[i-3];
	scanf("%d", &t);
	for(i=1; i<=t; i++){
		scanf("%d", &n);
		printf("%lld\n", d[n]);
	}
} 
