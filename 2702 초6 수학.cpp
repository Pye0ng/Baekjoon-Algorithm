#include<stdio.h>

int gcd(int a, int b){
	if(b==0) return a;
	else return gcd(b, a%b);
}

int main(){
	int t, a, b;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &a, &b);
		if(a>b) printf("%d %d\n", (a*b)/gcd(a, b), gcd(a, b));
		else printf("%d %d\n", (a*b)/gcd(b, a), gcd(b, a));
	}
}
