#include<stdio.h>

int main(){
	int n, t, s=0, i;
	scanf("%d", &n);
	for(i=0; i<5; i++){
		scanf("%d", &t);
		s+=n==t;
	}
	printf("%d", s);
}
