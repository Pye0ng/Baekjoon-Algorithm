#include<stdio.h>
int ans, c[60][60];

int main(){
	int n, m=10007, i, j;
	scanf("%d", &n);
	if(n<4){
		printf("0");
		return 0;	
	}
	for(i=0; i<=52; i++) c[i][0]=1;
	for(i=1; i<=52; i++)
		for(j=1; j<=i; j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%m;
	for(i=1; i<14&&n/(4*i); i++){
		j=i&1?1:-1;
		ans=(ans+j*(c[52-4*i][n-4*i]*c[13][i])%m+m)%m;
	}
	printf("%d", ans);
}
