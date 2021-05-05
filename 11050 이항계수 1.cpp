#include<stdio.h>

int main(){
	int n, k, com=1;
	scanf("%d %d", &n, &k);
	for(int i=n; i>n-k; i--) com*=i;
	for(int i=1; i<=k; i++) com/=i;
	printf("%d", com);
}
