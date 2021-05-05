#include<stdio.h>
double m, d[10010], dp[10010];

double mx(double a, double b){ return a>b?a:b; }

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%lf", &d[i]);
		mx(m, d[i]);
	}
	dp[1]=d[1];
	for(i=2; i<=n; i++){
		dp[i]=mx(d[i], d[i]*dp[i-1]);
		m=mx(m, dp[i]);
	}
	printf("%0.3lf", m);
}
