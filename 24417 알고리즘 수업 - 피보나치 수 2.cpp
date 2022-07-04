#include<stdio.h>

int main(){
	int a, b, c, n, t, m=1e9+7, i;
	scanf("%d", &n);
	a=b=c=1;
	for(i=3; i<=n; i++){
		a=b; b=c;
		c=(a+b)%m;
	}
	printf("%d %d", c, n-2);
}
