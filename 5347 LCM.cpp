#include<stdio.h>

long long int gcd(long long int a, long long int b){
	int n;
	if(a>=b){ while(a%b!=0){ n=a%b; a=b; b=n; } return b; }
	else{ while(b%a!=0){ n=b%a; b=a; a=n; } return a; }
} 

int main(){
	int n;
	long long int a, b;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", (a*b)/gcd(a, b));
	}
}
