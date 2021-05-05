#include<stdio.h>
int m, d[550][550], a[550][550];
int mx(int x, int y){ return x>y?x:y; }

int main(){
	int i, j, n;
	scanf("%d", &n);
	for(i=0; i<n; i++)
		for(j=0; j<=i; j++) scanf("%d", &d[i][j]);
	a[0][0]=d[0][0];
	for(i=1; i<n; i++){
		a[i][0]=d[i][0]+a[i-1][0];
		for(j=1; j<i; j++) a[i][j]=d[i][j]+mx(a[i-1][j-1], a[i-1][j]);
		a[i][i]=d[i][i]+a[i-1][i-1];
	}
	for(i=0; i<n; i++) m=mx(a[n-1][i], m);
	printf("%d", m);
}
