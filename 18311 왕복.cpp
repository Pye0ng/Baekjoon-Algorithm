#include<stdio.h>
int n, d[100100];
long long int a[100100], b[100100];
long long int k, sum;

int main(){
	int i;
	scanf("%d %lld", &n, &k);
	scanf("%d", &d[1]);
	a[1]=d[1];
	sum=d[1];
	for(i=2; i<=n; i++){
		scanf("%d", &d[i]);
		sum+=d[i];
		a[i]=a[i-1]+d[i];
	}
	b[n]=d[n];
	for(i=n-1; i>=1; i--) b[i]=b[i+1]+d[i]; 
	if(k>sum){
		int s=k-sum;
		for(i=n+1; i>=2; i--)
			if(b[i]<=s&&s<b[i-1]){
				printf("%d", i-1);
				return 0;
			}
	}
	else{
		for(i=0; i<n; i++)
			if(a[i]<=k&&k<a[i+1]){
				printf("%d", i+1);
				return 0;
			}
	}
}
