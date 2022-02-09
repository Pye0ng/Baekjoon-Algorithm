#include<stdio.h>
#define max(x, y) x>y?x:y
int w[210], v[210], d[210];

int main(){
	int n, k, i, j;
	scanf("%d %d", &n, &k);
	for(i=1; i<=k; i++) scanf("%d %d", &w[i], &v[i]);
	for(i=1; i<=k; i++)
		for(j=n; j>0; j--)
			if(j>=w[i]) d[j]=max(d[j], d[j-w[i]]+v[i]);
	printf("%d", d[n]);
}
