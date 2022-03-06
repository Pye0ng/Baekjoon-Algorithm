#include<stdio.h>
#include<vector>
using namespace std;
typedef long long int ll;
vector<int> s;
int p[251000];

void upd(int c, int a, int b, int i, int t){
	if(i<a||i>b) return;
	s[c]+=t; int m=(a+b)>>1;
	if(a==b) return;
	upd(c<<1, a, m, i, t);
	upd(c<<1|1, m+1, b, i, t);
}

ll find(int c, int a, int b, int t){
	if(a==b) return a;
	int m=(a+b)>>1;
	if(t<=s[c<<1]) return find(c<<1, a, m, t);
	else return find(c<<1|1, m+1, b, t-s[c<<1]);
}

int main(){
	int n, k, m, t=65536, i;
	scanf("%d %d", &n, &k); s.resize(150000);
	for(i=0; i<k; i++){
		scanf("%d", &m); p[i]=m;
		upd(1, 0, t, m, 1);
	}
	ll ans=find(1, 0, t, (k+1)/2);
	for(i=k; i<n; i++){
		scanf("%d", &m); p[i]=m;
		upd(1, 0, t, p[i-k], -1);
		upd(1, 0, t, m, 1);
		ans+=find(1, 0, t, (k+1)/2);
	}
	printf("%lld", ans);
}
