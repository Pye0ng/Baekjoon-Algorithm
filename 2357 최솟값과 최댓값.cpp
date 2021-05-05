#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, d[100010];
vector<int> mn_tree, mx_tree;

int nsg(int nw, int a, int b){
	if(a==b) return mn_tree[nw]=d[a];
	int md=(a+b)/2;
	mn_tree[nw]=min(nsg(2*nw, a, md), nsg(2*nw+1, md+1, b));
	return mn_tree[nw];
}

int xsg(int nw, int a, int b){
	if(a==b) return mx_tree[nw]=d[a];
	int md=(a+b)/2;
	mx_tree[nw]=max(xsg(2*nw, a, md), xsg(2*nw+1, md+1, b));
	return mx_tree[nw];
}

int mn(int nw, int a, int b, int p, int q){
	if(b<p||a>q) return 1e9+1;
	if(b<=q&&p<=a) return mn_tree[nw];
	int md=(a+b)/2;
	return min(mn(2*nw, a, md, p, q), mn(2*nw+1, md+1, b, p, q));
}

int mx(int nw, int a, int b, int p, int q){
	if(b<p||a>q) return 0;
	if(b<=q&&p<=a) return mx_tree[nw];
	int md=(a+b)/2;
	return max(mx(2*nw, a, md, p, q), mx(2*nw+1, md+1, b, p, q));
}

int main(){
	int i;
	mn_tree.resize(400100); mx_tree.resize(400010);
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	nsg(1, 1, n); xsg(1, 1, n);
	for(i=1; i<=m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d %d\n", mn(1, 1, n, a, b), mx(1, 1, n, a, b));
	}
}
