#include<stdio.h>
#include<vector>
using namespace std;
vector<int> s;
int a[100100], d[100100];

int seg(int c, int a, int b){
	if(a==b) return s[c]=1;
	int m=(a+b)>>1;
	return s[c]=seg(c<<1, a, m)+seg(c<<1|1, m+1, b);
}

int find(int c, int a, int b, int k){
	if(a==b) return a;
	int m=(a+b)>>1;
	return k<s[c<<1]?find(c<<1, a, m, k):find(c<<1|1, m+1, b, k-s[c<<1]);
}

void upd(int c, int a, int b, int t){
	if(t<a||t>b) return;
	if(a==b){ s[c]=0; return; }
	int m=(a+b)>>1;
	upd(c<<1, a, m, t);
	upd(c<<1|1, m+1, b, t);
	s[c]=s[c<<1]+s[c<<1|1];
}

int main(){
	int n, k, t, i;
	scanf("%d", &n); s.resize(n*4); seg(1, 1, n);
	for(i=1; i<=n; i++) scanf("%d", &a[i]);
	for(i=n; i>0; i--){
		t=find(1, 1, n, i-a[i]-1);
		d[t]=i; upd(1, 1, n, t);
	}
	for(i=1; i<=n; i++) printf("%d ", d[i]);
}
