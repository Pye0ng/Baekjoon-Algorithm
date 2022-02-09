#include<stdio.h> 
int c[25], d[10100];

int main(){
	int t, n, m, i, j;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(i=1; i<=n; i++) scanf("%d", &c[i]);
		scanf("%d", &m); d[0]=1;
		for(i=1; i<=n; i++)
			for(j=1; j<=m; j++)
				if(j>=c[i]) d[j]+=d[j-c[i]];
		printf("%d\n", d[m]);
		for(i=1; i<=m; i++) d[i]=0;
	}
}
