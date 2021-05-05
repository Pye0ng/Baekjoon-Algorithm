#include<stdio.h>

int main(){
	int a, b, c, d;
	scanf("%d %d", &a, &b);
	d=(a<=b)?a:b;
	for(int i=1; i<=d; i++){
		if(a%i==0&&b%i==0) c=i;
	}
	printf("%d\n%d", c, a*b/c);
}
