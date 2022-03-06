#include<stdio.h>
int max(int a, int b){ return a>b?a:b; }
int m, s, d[100100];

int main(){
	int n, k, i;
	scanf("%d %d", &n, &k);
	for(i=1; i<=n; i++){
		scanf("%d", &d[i]);
		if(i<=k) s+=d[i];
	}
	for(i=1; i<=n; i++){
		m=max(m, s);
		s-=d[i]; s+=i+k>n?d[i+k-n]:d[i+k];
	}
	printf("%d", m);
}
