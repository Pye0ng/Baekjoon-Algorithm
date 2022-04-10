#include<stdio.h>
#include<vector>
#include<set>
using namespace std;
pair<int, int> d[100100];
int n;

int lca(int a, int b){
	vector<bool> v(n, 0);
	for(int i=0; i<1000; i++){ v[a]=1; a=d[a].first; }
	for(int i=0; i<1000; i++){
		if(v[b]) return b;
		b=d[b].first;
	}
	return 0;
}

void paint(int a, int b, int c){
	int t=lca(a, b);
	while(a!=t){
		d[a].second=c;
		a=d[a].first;
	}
	while(b!=t){
		d[b].second=c;
		b=d[b].first;
	}
}

int count(int a, int b){
	set<int> s;
	int t=lca(a, b);
	while(a!=t){
		s.insert(d[a].second);
		a=d[a].first;
	}
	while(b!=t){
		s.insert(d[b].second);
		b=d[b].first;
	}
	return s.size();
}

int main(){
	int m, t, a, b, c, i;
	scanf("%d %d", &n, &m);
	for(i=1; i<n; i++) d[i]={0, 0};
	while(m--){
		scanf("%d %d %d", &t, &a, &b);
		if(t==1){
			scanf("%d", &c);
			paint(a, b, c);
		}
		else if(t==2) d[a].first=b;
		else printf("%d\n", count(a, b));
	}
}
