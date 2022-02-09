#include<stdio.h>
#define max(x, y) x>y?x:y
int w[110], v[110], d[10100];

int main(){
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++) scanf("%d", &v[i]);
	for(i=1; i<=n; i++) scanf("%d", &w[i]);
	for(i=1; i<=n; i++)
		for(j=10000; j>0; j--)
			if(j>=w[i]) d[j]=max(d[j], d[j-w[i]]+v[i]);
	for(j=1; j<10001; j++)
		if(d[j]>=m){
			printf("%d", j);
			break;
		}
}
