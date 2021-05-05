#include<stdio.h>
#include<vector>
using namespace std;
int n, m;

void purmu(vector<int> v, int l){
	int i;
	if(l==m){
		for(i=0; i<m; i++) printf("%d ", v[i]);
		printf("\n"); return;
	}
	for(int i=v.back(); i<=n; i++){
		vector<int> t; t=v;
		t.push_back(i);
		purmu(t, l+1);
	}
}

int main(){
	int i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		vector<int> v;
		v.push_back(i);
		purmu(v, 1);
	}
}
