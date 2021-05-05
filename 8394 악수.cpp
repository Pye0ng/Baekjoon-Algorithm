#include<stdio.h>
int n, i, d[10000010];

int main(){
	int n, i;
	scanf("%d", &n);
	d[2]=2; d[3]=3;
	for(i=4; i<=n; i++) d[i]=(d[i-1]%10+d[i-2]%10)%10;
	printf("%d", d[n]);
}
