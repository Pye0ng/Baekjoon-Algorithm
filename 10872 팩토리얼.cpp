#include<stdio.h>

int main(){
	int n, m=1;
	scanf("%d", &n);
	while(n>1) m*=n--;
	printf("%d", m); 
}
