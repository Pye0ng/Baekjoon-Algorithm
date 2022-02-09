#include<stdio.h>
#define max(x, y) x>y?x:y
int b[110][3], d[310][310];

int main(){
	int n, m, k, i, j, p;
	scanf("%d %d %d", &n, &m, &k);
	for(i=1; i<=n; i++) scanf("%d %d", &b[i][0], &b[i][1]);
	for(i=1; i<=n; i++)
		for(j=m; j>0; j--)
			for(p=k; p>0; p--)
				if(j>=b[i][0]&&p>=b[i][1]) d[j][p]=max(d[j][p], d[j-b[i][0]][p-b[i][1]]+1);
	printf("%d", d[m][k]);
}
