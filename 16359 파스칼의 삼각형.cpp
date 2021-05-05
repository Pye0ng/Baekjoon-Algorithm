#include<stdio.h> 
int n, k, p[31][31];

int main(){
	p[1][1]=1;
	scanf("%d %d", &n, &k);
	for(int i=2; i<=n; i++)
		for(int j=1; j<=i; j++) p[i][j]=p[i-1][j]+p[i-1][j-1];
	printf("%d", p[n][k]); 
}
