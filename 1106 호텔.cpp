#include<stdio.h>
int max(int a, int b){ return a>b?a:b; }
int d[101000];

int main(){
	int w, v, c, n, k, i, j;
	scanf("%d %d", &c, &n);
	for(i=0; i<n; i++){
		scanf("%d %d", &w, &v);
		for(j=1; j<=100100; j++)
			if(j>=w) d[j]=max(d[j], d[j-w]+v);
	}
	for(i=100100; i>0; i--)
		if(d[i]>=c) k=i;
	printf("%d", k);
}
