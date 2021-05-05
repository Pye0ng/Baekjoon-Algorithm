#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, d[10];

void p(vector<int> v, int l){
	int i;
	if(l==m){
		for(i=0; i<m; i++) printf("%d ", d[v[i]]);
		printf("\n"); return;
	}
	for(i=v.back(); i<n; i++){
		vector<int> t;
		t=v; t.push_back(i);
		p(t, l+1);
	}
}

int main(){
	int i;
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++) scanf("%d", &d[i]);
	sort(d, d+n);
	for(i=0; i<n; i++){
		vector<int> v;
		v.push_back(i);
		p(v, 1);
	}
}
