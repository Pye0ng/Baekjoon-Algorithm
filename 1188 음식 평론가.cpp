#include<stdio.h>

int gcd(int a, int b){
	int n;
	if(a>=b){ while(a%b!=0){ n=a%b; a=b; b=n; } return b; }
	else{ while(b%a!=0){ n=b%a; b=a; a=n; } return a; }
}

int main(){
	int n, m, k, i;
	scanf("%d %d", &n, &m);
	k=gcd(n, m);
	printf("%d", m-k);
}
