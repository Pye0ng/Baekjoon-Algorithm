#include<stdio.h>

int gcd(int a, int b){ return !b?a:gcd(b, a%b); }

int ie(int a, int b){
	
}

int main(){
	int t, m, n, x, y, g;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d", &m, &n, &x, &y);
		g=m>n?gcd(m, n):gcd(n, m);
		if(x%g!=y%g) printf("-1\n");
		//else printf("%d\n", (n*ie(n, m)*x+m*ie(m, n)*y)%(m*n/g));
	}
}
