#include<stdio.h>

int gcd(int a, int b){
	int n;
	if(a>=b){ while(a%b!=0){ n=a%b; a=b; b=n; } return b; }
	else{ while(b%a!=0){ n=b%a; b=a; a=n; } return a; }
}

int lcm(int a, int b){ return a*b/gcd(a, b); }

int main(){
	int n, a, b;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", lcm(a, b));
	}
}
