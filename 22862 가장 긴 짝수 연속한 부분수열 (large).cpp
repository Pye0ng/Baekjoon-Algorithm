#include<stdio.h>
int m, s[1000100];

int main(){
	int n, k, p, q, e, i;
	scanf("%d %d", &n, &k);
	for(i=1; i<=n; i++){
		scanf("%d", &p);
		s[i]=s[i-1]+p%2;
	}
	p=1; q=1;
	while(p<=n&&q<=n){
		while(s[q]-s[p-1]<=k&&q<n){
			q++; e=q-p+1-s[q]+s[p-1];
			if(e>m) m=e;
		}
		e=q-p+1-s[q]+s[p-1];
		if(e>m) m=e;
		if(q==n) break;
		p++;
	}
	printf("%d", m);
}
