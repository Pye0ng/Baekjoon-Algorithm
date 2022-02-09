#include<stdio.h>
#define max(x, y) x>y?x:y
#define min(x, y) x<y?x:y
typedef long long int ll;
ll p, q, m, M, mid, sum, mn=1e13, d[1000100];

int main(){
	int n, i;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%lld", &d[i]);
		M=max(M, d[i]);
	}
	p=0; q=M*m+1;
	while(p<q){
		sum=0;
		mid=(p+q)>>1;
		for(i=1; i<=n; i++) sum+=(mid/d[i]);
		if(sum>=m){
			q=mid;
			mn=min(mn, mid);
		}
		else p=mid+1;
	}
	printf("%lld", mn);
}
