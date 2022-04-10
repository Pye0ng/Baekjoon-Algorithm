#include<stdio.h>
typedef long long int ll;
int max(ll a, ll b){ return a>b?a:b; }

int main(){
	ll a, b, c, m, p=0, t=0, w=0;
	scanf("%lld %lld %lld %lld", &a, &b, &c, &m);
	if(a>m){ printf("0"); return 0; }
	while(1){
		if(p+a>m) p=max(p-c, 0);
		else{ p+=a; w+=b; }
		if(++t==24) break;
	}
	printf("%lld", w);
}
