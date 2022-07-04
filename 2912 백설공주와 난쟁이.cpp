#include<stdio.h>
#include<random>
#include<algorithm>
#include<vector>
using namespace std;
int d[300100];
vector<int> v[10100];

int main(){
	int n, m, p, q, ch, idx, i;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> ran(0, 2147483647);
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", &d[i]);
		if(v[d[i]].empty()) v[d[i]].push_back(-1);
		v[d[i]].push_back(i);
	}
	scanf("%d", &m);
	while(m--){
		ch=-1;
		scanf("%d %d", &p, &q);
		for(i=1; i<31; i++){
			idx=ran(gen)%(q-p+1)+p;
			idx=d[idx];
			if(upper_bound(v[idx].begin(), v[idx].end(), q)-lower_bound(v[idx].begin(), v[idx].end(), p)>(q-p+1)/2){ ch=idx; break; }
		}
		if(ch<0) printf("no\n");
		else printf("yes %d\n", ch);
	}
}
