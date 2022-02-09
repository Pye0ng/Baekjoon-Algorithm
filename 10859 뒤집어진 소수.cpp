#include<stdio.h>
typedef long long int ll;
bool c=0; 

ll rvs(ll n){
	ll t, r=0;
	while(n>0){
		r*=10; t=n%10; n/=10;
		if(t==3||t==4||t==7) c=1;
		else if(t==6) r+=9;
		else if(t==9) r+=6;
		else r+=t;
	}
	return r;
}

bool prime(ll n){
	if(n==1) return 1;
	for(ll i=2; i*i<=n; i++)
		if(n%i==0) return 1;
	return 0;
}


int main(){
	ll n, m;
	scanf("%lld", &n);
	m=rvs(n); if(prime(n)||prime(m)) c=1;
	if(c) printf("no");
	else printf("yes");
}
