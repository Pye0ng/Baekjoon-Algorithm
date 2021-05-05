#include<stdio.h>
int n, m=1, d[100010], dp1[100010], dp2[100010];
int max(int a, int b){ return a>b?a:b; }

int main(){
	int i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	dp1[1]=dp2[1]=1;
	for(i=2; i<=n; i++){
		dp1[i]=dp2[i]=1;
		if(d[i]>=d[i-1]) dp1[i]=dp1[i-1]+1;
		if(d[i]<=d[i-1]) dp2[i]=dp2[i-1]+1;
		m=max(m, max(dp1[i], dp2[i]));
	}
	printf("%d", m);
}
