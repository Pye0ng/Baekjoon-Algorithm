#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int n, m, d[100010];

int sg(int nw, int a, int b){
	if(a==b) return v[nw]=d[a];
	int md=(a+b)/2;
	return v[nw]=min(sg(2*nw, a, md), sg(2*nw+1, md+1, b));
}

int mn(int nw, int a, int b, int p, int q){
	if(b<p||a>q) return 1e9+1;
	if(b<=q&&a>=p) return v[nw];
	int md=(a+b)/2;
	return min(mn(2*nw, a, md, p, q), mn(2*nw+1, md+1, b, p, q));
}

int ud(int nw, int a, int b, int index, int t){
	if(a<=index&&index<=b){
		if(a==b) v[nw]=t; 
		else{
			int md=(a+b)/2;
			v[nw]=min(ud(2*nw, a, md, index, t), ud(2*nw+1, md+1, b, index, t));
		}
	}
	return v[nw];
}

int main(){
	int i;
	v.resize(400100);
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	sg(1, 1, n);
	scanf("%d", &m);
	while(m--){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(a==1){ ud(1, 1, n, b, c); d[b]=c; }
		else{
			if(b>c) swap(b, c);
			printf("%d\n", mn(1, 1, n, b, c));
		}
	}
} 
