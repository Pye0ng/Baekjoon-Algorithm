#include<stdio.h>
#define abs(t) t>0?t:-t
int a[110], d[110][1050];

int main(){
	int n, m, i, j, k;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", &j);
		a[i]=abs(j); d[1][a[i]]=1;
	}
	for(i=2; i<=m; i++)
		for(j=1; j<=n; j++)
			for(k=1024; k>=0; k--)
				if(d[i-1][k]) d[i][k^a[j]]=d[i-1][k];
	for(i=1024; i>=0; i--)
		if(d[m][i]){
			printf("%d", i);
			break;
		}
}
