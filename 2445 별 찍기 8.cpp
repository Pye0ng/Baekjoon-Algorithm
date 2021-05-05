#include<stdio.h>
int main(){
	int n, i, j;
	scanf("%d", &n);
	for(i=1; i<n; i++){
		for(j=1; j<=i; j++) printf("*");
		for(j=1; j<=2*(n-i); j++) printf(" ");
		for(j=1; j<=i; j++) printf("*");
		printf("\n");
	}
	for(i=1; i<=2*n; i++) printf("*");
	printf("\n");
	for(i=n-1; i>0; i--){
		for(j=1; j<=i; j++) printf("*");
		for(j=1; j<=2*(n-i); j++) printf(" ");
		for(j=1; j<=i; j++) printf("*");
		printf("\n");
	}
}
