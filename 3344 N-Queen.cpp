#include<stdio.h>

int main(){
	int n, i;
	scanf("%d", &n);
	if(n%6==2){
		for(i=2; i<=n; i+=2) printf("%d\n", i);
		printf("3\n1\n");
		for(i=7; i<=n; i+=2) printf("%d\n", i);
		printf("5");
	}
	else if(n%6==3){
		for(i=4; i<=n; i+=2) printf("%d\n", i);
		printf("2\n");
		for(i=5; i<=n; i+=2) printf("%d\n", i);
		printf("1\n3");
	}
	else{
		for(i=2; i<=n; i+=2) printf("%d\n", i);
		for(i=1; i<=n; i+=2) printf("%d\n", i);
	}
}
