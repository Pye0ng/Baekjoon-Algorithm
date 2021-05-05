#include<stdio.h>
int n, k, d[100010];

int main(){
	int i, j;
	scanf("%d", &n);
	d[1]=1;
	for(i=2; i<=n; i++){
		k=999999999;
		for(j=1; j*j<=i; j++){
			int t=i-j*j;
			if(d[t]<k) k=d[t];
		}
		d[i]=k+1;
	}
	printf("%d", d[n]);
}
