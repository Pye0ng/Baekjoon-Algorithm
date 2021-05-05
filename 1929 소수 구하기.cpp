#include<stdio.h>
int a[1000001];

void prime(int n){
	int i;
	for(i=2; i<=n; i++) a[i]=1;
	for(i=2; i<=n; i++){
		if(a[i]==0) continue;
		for(int j=2*i; j<=n; j+=i) a[j]=0;
	}
}

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	prime(n);
	for(int i=m; i<=n; i++){ if(a[i]) printf("%d\n", i); }
}
