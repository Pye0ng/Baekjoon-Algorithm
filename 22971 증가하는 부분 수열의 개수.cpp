#include<stdio.h>
int m=998244353, d[5050], p[5050];

int main(){
	int n, i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &d[i]); p[i]=1;
		for(j=1; j<i; j++)
			if(d[j]<d[i]) p[i]=(p[i]+p[j])%m;
		printf("%d ", p[i]);
	}
}
