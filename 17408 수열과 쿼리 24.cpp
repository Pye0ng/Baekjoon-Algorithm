#include<stdio.h>
#include<algorithm>
#include<vector>
#define x first
#define y second
using namespace std;
typedef pair<int, int> p;
vector<p> s;
int d[100100];

p cmp(p a, p b){
	vector<int> v;
	v.push_back(a.x);
	v.push_back(b.x);
	v.push_back(a.y);
	v.push_back(b.y);
	sort(v.begin(), v.end());
	return {v[3], v[2]};
}

p seg(int c, int a, int b){
	if(a==b) return s[c]={d[a], 0};
	int m=(a+b)/2;
	return s[c]=cmp(seg(c*2, a, m), seg(c*2+1, m+1, b));
}

p sum(int c, int a, int b, int l, int r){
	if(a>r||b<l) return {0, 0};
	if(l<=a&&b<=r) return s[c];
	int m=(a+b)/2;
	return cmp(sum(c*2, a, m, l, r), sum(c*2+1, m+1, b, l, r));
}

p upd(int c, int a, int b, int n, int t){
	if(n<a||n>b) return s[c];
	if(a!=b){
		int m=(a+b)/2;
		return s[c]=cmp(upd(c*2, a, m, n, t), upd(c*2+1, m+1, b, n, t));
	}
	else return s[c]={t, 0};
}

int main(){
	int n, m, a, b, c, i;
	scanf("%d", &n); s.resize(n*4);
	for(i=1; i<=n; i++) scanf("%d", &d[i]);
	seg(1, 1, n); scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%d %d %d", &a, &b, &c);
		if(a&1){ d[b]=c; upd(1, 1, n, b, c); }
		else{
			p t=sum(1, 1, n, b, c);
			printf("%d\n", t.x+t.y); 
		}
	}
}
