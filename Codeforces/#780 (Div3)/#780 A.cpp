#include<stdio.h>

int main(){
	int n, a, b, i;
	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &a, &b);
		printf("%d\n", a==0?1:b*2+a+1);
	}
}
