#include<stdio.h>
long long int d[100100], sm[100100], sum;

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%lld", &d[i]);
	for(i=n; i>=0; i--) sm[i]=sm[i+1]+d[i]; 
	for(i=0; i<n-1; i++) sum+=d[i]*sm[i+1];
	printf("%lld", sum);
}
