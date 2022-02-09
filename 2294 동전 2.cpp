#include<stdio.h>
#define min(x, y) x<y?x:y
int c[110], d[10100];

int main(){
	int n, k, i, j;
	scanf("%d %d", &n, &k);
	for(i=1; i<=n; i++) scanf("%d", &c[i]);
	for(i=1; i<=k; i++){
		d[i]=1e7;
		for(j=1; j<=n; j++)
			if(i>=c[j]) d[i]=min(d[i], d[i-c[j]]+1);
	}
	if(d[k]!=1e7) printf("%d", d[k]);
	else printf("-1");
}
