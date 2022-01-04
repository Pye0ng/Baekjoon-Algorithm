#include<stdio.h>
int p[1010][1010];

int main(){
	int R, C, q, k, i, j;
	scanf("%d %d %d", &R, &C, &q);
	for(i=1; i<=R; i++)
		for(j=1; j<=C; j++){
			scanf("%d", &k);
			p[i][j]=k+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
		}
	while(q--){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d\n", (p[c][d]-p[a-1][d]-p[c][b-1]+p[a-1][b-1])/((c-a+1)*(d-b+1)));
	}
}
