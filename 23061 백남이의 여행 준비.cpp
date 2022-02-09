#include<stdio.h>
#include<utility>
#define max(x, y) x>y?x:y
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> p;
ll w[110], v[110], b[110], d[1000100];
int k; p f, t;

bool cmp(){
	ll l=f.first*t.second, r=f.second*t.first;
	if(r>=l) return 1;
	else return 0;
}

int main(){
	int n, m, i, j; f={0, 1};
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++) scanf("%lld %lld", &w[i], &v[i]);
	for(i=1; i<=m; i++){
		scanf("%lld", &b[i]);
		if(b[i]>k) k=b[i];
	}
	for(i=1; i<=n; i++)
		for(j=k; j>0; j--)
			if(j>=w[i]) d[j]=max(d[j], d[j-w[i]]+v[i]);
	for(i=m; i>0; i--){
		t={d[b[i]], b[i]};
		if(cmp()){ f=t; k=i; }
	}
	printf("%d", k);
}
