#include<stdio.h>
int n, k, dp0[41], dp1[41];

int main(){
	int i, j;
	scanf("%d", &n);
	dp0[0]=dp1[1]=1; 
	dp0[1]=dp1[0]=0; 
	for(i=2; i<=40; i++){
		dp0[i]=dp0[i-1]+dp0[i-2];
		dp1[i]=dp1[i-1]+dp1[i-2];
	}
	for(i=1; i<=n; i++){
		scanf("%d", &k);
		printf("%d %d\n", dp0[k], dp1[k]);
	}
}
