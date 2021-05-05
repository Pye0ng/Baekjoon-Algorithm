#include<stdio.h>
int n, t, m=1e4+7, d[1010][11];

int main(){
	int i, j, k;
	for(i=0; i<=9; i++) d[1][i]=1;
	scanf("%d", &n);
	for(i=2; i<=n; i++){
		for(j=0; j<=9; j++){
			for(k=j; k<=9; k++) d[i][j]+=d[i-1][k];
			d[i][j]%=m;
		}
	}
	for(i=0; i<=9; i++) t+=d[n][i];
	printf("%d", t%m);
}
