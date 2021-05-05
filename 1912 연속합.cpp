#include<stdio.h>
int a[100001], dp[100001];
int n, mx=-2100000000;

void max(int k){ if(k>mx) mx=k; }

int main(){
	int i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &a[i]);
	max(a[1]);
	for(i=2; i<=n; i++){
		if(a[i-1]>0&&a[i]+a[i-1]>0) a[i]+=a[i-1];
		max(a[i]);
	}
	printf("%d", mx); 
}
