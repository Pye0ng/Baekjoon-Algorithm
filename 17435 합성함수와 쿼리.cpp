#include<stdio.h>
int d[200100], s[25][200100];

int main(){
	int n, m, a, b, i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &d[i]);
		s[0][i]=d[i];
	}
	for(i=1; i<20; i++)
		for(j=1; j<=n; j++)
			s[i][j]=s[i-1][s[i-1][j]];
	scanf("%d", &m);
	while(m--){
		scanf("%d %d", &a, &b);
		for(i=19; i>=0; i--)
			if(a&(1<<i)) b=s[i][b];
		printf("%d\n", b);
	}
}
