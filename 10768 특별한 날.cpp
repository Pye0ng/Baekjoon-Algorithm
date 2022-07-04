#include<stdio.h>
int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	if(a<2) printf("Before");
	else if(a==2){
		if(b<18) printf("Before");
		else if(b==18) printf("Special");
		else printf("After");
	}
	else printf("After");
}
