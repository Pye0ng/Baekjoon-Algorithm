#include<stdio.h>
int abs(int t){ return t>0?t:-t; }
int min(int a, int b){ return a<b?a:b; }

int main(){
	int n, a, b, m, t, i;
	scanf("%d %d %d", &a, &b, &n);
	m=abs(b-a);
	for(i=1; i<=n; i++){
		scanf("%d", &t);
		m=min(m, abs(t-b)+1);
	}
	printf("%d", m);
}
