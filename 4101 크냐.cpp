#include<stdio.h>

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	while(a){
		printf("%s\n", a>b?"Yes":"No");
		scanf("%d %d", &a, &b);
	}	
}
