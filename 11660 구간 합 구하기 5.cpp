#include<stdio.h>
typedef long long int ll;
int n, m, k, x1, x2, y1, y2;
ll d[1030][1030];

int main(){
	int i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++){
			scanf("%d", &k);
			d[i][j]=k+d[i][j-1]+d[i-1][j]-d[i-1][j-1];
		}
	while(m--){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%lld\n", d[x2][y2]-d[x1-1][y2]-d[x2][y1-1]+d[x1-1][y1-1]);
	}
}
