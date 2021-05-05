#include<stdio.h>

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) if(30%(i+1)==0) printf("%d\n", i);
}
