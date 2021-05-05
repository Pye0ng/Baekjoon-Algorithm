#include<stdio.h>
typedef long long int ll;
int cnt;
ll n;

ll rt(ll k){ return k*(k+1)/2; }

int main(){
	scanf("%lld", &n);
	int p=0, q=1;
	while(p<q){
		int s=rt(q)-rt(p);
		if(s==n){
			cnt++;
			p++;
		}
		else if(s<n) q++;
		else p++;
	} 
	printf("%d", cnt);
}
