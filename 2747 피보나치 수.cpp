#include<stdio.h>

int memo[100];
int f(unsigned int n){
	if(n<=1) return n;
	if(memo[n]!=0) return memo[n];
	memo[n]=f(n-1)+f(n-2);
	return memo[n];
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", f(n));
}
