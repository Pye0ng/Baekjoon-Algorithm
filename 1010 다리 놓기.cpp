#include<stdio.h>
long long int d[40][40]; 

int main(){
	int t, i, j;
	scanf("%d", &t);
	for(i=0; i<=32; i++){
		d[i][0]=1;
		for(j=1; j<=i; j++) d[i][j]=d[i-1][j]+d[i-1][j-1];
	}
	for(i=1; i<=t; i++){
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%lld\n", d[m][n]);
	}
}
