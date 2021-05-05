#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, d[100010];
vector<int> v;

int sg(int nw, int a, int b){
	if(a==b) return v[nw]=d[a];
	int md=(a+b)/2;
	return v[nw]=min(sg(2*nw, a, md), sg(2*nw+1, md+1, b));
}

int mn(int nw, int a, int b, int p, int q){
	if(b<p||a>q) return 1e9+1;
	if(b<=q&&p<=a) return v[nw];
	int md=(a+b)/2;
	return min(mn(2*nw, a, md, p, q), mn(2*nw+1, md+1, b, p, q));
}

int main(){
	int i;
	v.resize(400100);
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	sg(1, 1, n);
	for(i=1; i<=m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", mn(1, 1, n, a, b));
	}
}
