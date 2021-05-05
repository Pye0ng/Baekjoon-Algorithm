#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int cnt, n, m, k, x, d[300010];
vector<int> v[300010];
queue<int> q;

int main(){
	int i;
	scanf("%d %d %d %d", &n, &m, &k, &x);
	for(i=1; i<=m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
	}
	q.push(x);
	while(!q.empty()){
		int s=q.front();
		q.pop();
		for(i=0; i<v[s].size(); i++)
			if(d[v[s][i]]==0){
				d[v[s][i]]=d[s]+1;
				q.push(v[s][i]);
			}	
	}
	d[x]=0;
	for(i=1; i<=n; i++) 
		if(d[i]==k){
			cnt=1;
			printf("%d\n", i);
		}
	if(cnt==0) printf("-1");
}
