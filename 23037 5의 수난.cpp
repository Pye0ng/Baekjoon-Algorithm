#include<stdio.h>
int n, sum;

int f(int t){ return t*t*t*t*t; }

int main(){
	scanf("%d", &n);
	while(n>0){
		sum+=f(n%10);
		n/=10;
	}
	printf("%d", sum);
}
