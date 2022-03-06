#include<stdio.h>
int min(int a, int b){ return a<b?a:b; }
int a, d[1000100];

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &d[i]);
		a=-min(-a, -d[i]);
	}
	for(i=2; i<n; i++) a=-min(-a, -d[i]-min(d[i-1], d[i+1]));
	printf("%d", a);
}
