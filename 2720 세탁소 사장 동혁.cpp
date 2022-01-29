#include<stdio.h>

int main(){
	int n, a, b, c, t;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		a=n/25; n%=25;
		b=n/10; n%=10;
		c=n/5; n%=5;
		printf("%d %d %d %d\n", a, b, c, n);
	}
}
