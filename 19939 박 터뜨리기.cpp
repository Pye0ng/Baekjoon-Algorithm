#include<stdio.h>

int main(){
	int n, k, t;
	scanf("%d %d", &n, &k);
	t=k*(k+1)/2;
	printf("%d", t>n?-1:t<n&&(n-t)%k?k:k-1);
}
