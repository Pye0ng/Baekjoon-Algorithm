#include<stdio.h>
#include<math.h>
long long int x[10010], y[10010];

int main(){
	int n, i;
	long long int ans=0;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%lld %lld", &x[i], &y[i]);
	x[n+1]=x[1]; y[n+1]=y[1];
	for(i=1; i<=n; i++) ans+=x[i]*y[i+1]-x[i+1]*y[i];
	printf("%.1lf", (double)abs(ans)/2);
}
