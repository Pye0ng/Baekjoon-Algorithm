#include<stdio.h>
#include<math.h>
int n, k, i, j;
int d[50010];

int min(int a, int b){ return a<b?a:b; }

int main(){
	scanf("%d", &n);
	d[1]=1;
	for(i=2; i<=n; i++){
		k=99999999;
		for(j=1; j*j<=i; j++){
			int t=i-j*j;
			k=min(k, d[t]);
		}
		d[i]=k+1;
	}
	printf("%d", d[n]);
}
