#include<stdio.h>
int n, cnt, a[1000100], dp[1000100];

int lower_bound(int k){
	int s=0, e=cnt;
	while(e>s){
		int m=(s+e)/2;
		if(dp[m]<k) s=m+1;
		else e=m;
	}
	return e;
}

int main(){
	int i;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &a[i]);
	dp[0]=a[0];
	for(i=1; i<n; i++){
		if(dp[cnt]<a[i]) dp[++cnt]=a[i];
		else dp[lower_bound(a[i])]=a[i];
	}
	printf("%d", cnt+1);
}
