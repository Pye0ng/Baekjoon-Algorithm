#include<stdio.h>
int t, n, m, M=1e9+9;
long long int d[1010][1010];

int main(){
	int i, j;
	scanf("%d", &t);
	d[1][1]=d[2][1]=d[3][1]=d[2][2]=d[3][3]=1;
	d[3][2]=2;
	for(i=4; i<=1000; i++)
		for(j=1; j<=i; j++)
			d[i][j]=(d[i-1][j-1]+d[i-2][j-1]+d[i-3][j-1])%M;
	while(t--){
		scanf("%d %d", &n, &m);
		printf("%lld\n", d[n][m]);
	}
}
