#include<stdio.h>

int main(){
	long long int a, b;
	scanf("%lld %ld", &a, &b);
	printf("%lld", a>b?a-b:b-a);
}
