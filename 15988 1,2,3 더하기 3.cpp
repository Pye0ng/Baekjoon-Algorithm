#include<stdio.h>
#define M 1000000009
int n, k, i, d[1000010];

int main(){
	scanf("%d", &n);
	d[0]=d[1]=1; d[2]=2;
	while(n--){
		scanf("%d", &k);
		for(i=3; i<=k; i++) d[i]=((d[i-1]+d[i-2])%M+d[i-3])%M;
		printf("%d\n", d[k]);
	}
}
