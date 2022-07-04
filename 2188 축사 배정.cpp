#include<stdio.h>
#include<vector>
using namespace std;
vector<int> g[420], p(420, -1);
int ans, cnt, v[420];

int match(int t){
	for(auto i:g[t]){
		if(v[i]==cnt) continue;
		v[i]=cnt;
		if(p[i]==-1||match(p[i])){
			p[i]=t;
			return 1;
		}
	}
	return 0;
}

int main(){
	int n, m, i;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		int a, b;
		scanf("%d", &a);
		while(a--){
			scanf("%d", &b);
			g[i].push_back(b+200);
		}
	}
	for(i=1; i<=n; i++){
		++cnt;
		if(match(i)) ans++;
	}
	printf("%d", ans);
}
