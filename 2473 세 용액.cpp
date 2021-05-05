#include<stdio.h>
#include<algorithm>
typedef long long int ll;
ll s, m=3e9+1, d[5010];
ll abs(ll t){ return t>0?t:-t; }

int main(){
	int n, a, b, c, p, q, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%lld", &d[i]);
	std::sort(d+1, d+n+1);
	for(i=1; i<n-1; i++){
		p=i+1; q=n;
		while(p<q){
			s=d[i]+d[p]+d[q];
			if(abs(s)<m){ m=abs(s); a=d[i]; b=d[p]; c=d[q]; }
			if(s>=0) q--;
			else p++;
		} 
	}
	printf("%d %d %d", a, b, c);
}
