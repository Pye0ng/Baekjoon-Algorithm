#include<stdio.h>
int n, k, sum;
int a[11];

int main(){
	int i;
	scanf("%d %d", &n, &k);
	for(i=1; i<=n; i++) scanf("%d", &a[i]);
	for(i=n; i>=1; i--){
		while(a[i]<=k){
			k-=a[i];
			sum++;
		}
	}
	printf("%d", sum);
}
