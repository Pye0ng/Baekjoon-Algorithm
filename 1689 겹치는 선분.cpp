#include<stdio.h>
#include<utility>
#include<algorithm>
using namespace std;
pair<int, int> p[2000020];
int m, t;

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		p[i]={a, 1};
		p[i+n]={b, -1};
	}
	sort(p, p+2*n);
	for(i=0; i<2*n; i++){
		t+=p[i].second;
		m=max(t, m);
	}
	printf("%d", m);
}
