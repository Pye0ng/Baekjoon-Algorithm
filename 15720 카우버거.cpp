#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> a, b, c;
bool cmp(int p, int q){ return p>q; }

int main(){
	int A, B, C, m, s=0, t, i;
	scanf("%d %d %d", &A, &B, &C);
	m=min(min(A, B), C);
	for(i=0; i<A; i++){
		scanf("%d", &t);
		a.push_back(t); s+=t;
	}
	sort(a.begin(), a.end(), cmp);
	for(i=0; i<B; i++){
		scanf("%d", &t);
		b.push_back(t); s+=t;
	}
	sort(b.begin(), b.end(), cmp);
	for(i=0; i<C; i++){
		scanf("%d", &t);
		c.push_back(t); s+=t;
	}
	sort(c.begin(), c.end(), cmp);
	t=0;
	for(i=0; i<m; i++) t+=a[i]+b[i]+c[i];
	t=int(t*0.9);
	for(i=m; i<max(max(A, B), C); i++){
		if(A>i) t+=a[i];
		if(B>i) t+=b[i];
		if(C>i) t+=c[i];
	}
	printf("%d\n%d", s, t);
}
