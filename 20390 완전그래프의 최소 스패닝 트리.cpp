#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef __int128 i128;
ll a, b, c, d, s, INF=1e18, p[10100], x[10100];
int v[10100];

ll w(int i, int j){
	if(i>j) swap(i, j);
	return (((i128)x[i]*a+(i128)x[j]*b)%c)^d;
} 

int main(){
	int n, t, i, j; ll mn;
	scanf("%d %lld %lld %lld %lld", &n, &a, &b, &c, &d);
	for(i=1; i<=n; i++) scanf("%lld", &x[i]);
	for(i=2; i<=n; i++) p[i]=INF;
	for(i=1; i<=n; i++){
		mn=INF;
		for(j=1; j<=n; j++)
			if(!v[j]&&mn>p[j]){
				mn=p[j];
				t=j;
			}
		s+=mn; v[t]=1;
		for(j=1; j<=n; j++)
			p[j]=min(p[j], w(t, j));
	}
	printf("%lld", s);
}
