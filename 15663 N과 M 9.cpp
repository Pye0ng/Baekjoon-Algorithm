#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
set<vector<int> > s;
vector<int> t;

int main(){
	int n, m, k, i, j;
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++){
		scanf("%d", &k);
		t.push_back(k);
	}
	sort(t.begin(), t.end());
	do{
		vector<int> v;
		v.assign(t.begin(), t.begin()+m);
		s.insert(v);
	}while(next_permutation(t.begin(), t.end()));
	for(auto it=s.begin(); it!=s.end(); it++){
		vector<int> v; v=*it;
		for(i=0; i<m; i++) printf("%d ", v[i]);
		printf("\n");
	}
}
