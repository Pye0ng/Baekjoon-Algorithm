#include<stdio.h>

int main(){
	int R, r;
	scanf("%d %d", &R, &r);
	printf("%lld", (long long int)R*(R-2*r));
}
