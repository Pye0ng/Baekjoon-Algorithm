#include<stdio.h>
#include<vector>
using namespace std;
vector<int> fir, visit;

int dfs(int s, int n, int cnt, int d[]){
	if(visit[n]){
		if(fir[n]!=s) return 0;
		return cnt-visit[n];
	}
	fir[n]=s;
	visit[n]=cnt;
	return dfs(s, d[n], cnt+1, d);
}

int main(){
	int t, n, i;
	scanf("%d", &t);
	while(t--){
		int ans=0, d[100010]={};
		scanf("%d", &n);
		fir=vector<int> (n+1, 0);
		visit=vector<int> (n+1, 0);
		for(i=1; i<=n; i++) scanf("%d", &d[i]);
		for(i=1; i<=n; i++)
			if(!visit[i]) ans+=dfs(i, i, 1, d);
		printf("%d\n", n-ans);
	}
}
