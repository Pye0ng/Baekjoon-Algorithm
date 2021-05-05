#include<stdio.h>
int main(){
	int n, i, j;
	scanf("%d", &n);
	for(i=n; i>0; i--){
		for(j=n; j>i; j--) printf(" ");
		for(j=1; j<=2*i-1; j++) printf("*");
		printf("\n");
	}
}
