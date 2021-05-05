#include<stdio.h>
#include<memory.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v[10100];
int n, m, cnt, mx, ans[10100];
bool visited[10100];

void find(int k){
	cnt++;
	visited[k]=1;
	for(int i=0; i<v[k].size(); i++)
		if(!visited[v[k][i]]) find(v[k][i]);
}

int main(){
	int i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[b].push_back(a);
	}
	for(i=1; i<=n; i++){
		cnt=0;
		find(i);
		ans[i]=cnt;
		if(cnt>mx) mx=cnt;
		memset(visited, 0, sizeof(visited));
	}
	for(i=1; i<=n; i++)
		if(ans[i]==mx) printf("%d ", i);
}
