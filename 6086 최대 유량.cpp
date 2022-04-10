#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int ans, c[60][60], f[60][60], v[60];
vector<int> g[60];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	char r, s;
	int n, m, a, t, i;
	cin>>n;
	for(i=0; i<n; i++){
		cin>>r>>s>>t;
		m=r>'Z'?r-'a'+26:r-'A';
		a=s>'Z'?s-'a'+26:s-'A';
		g[m].push_back(a);
		g[a].push_back(m);
		c[m][a]+=t;
		c[a][m]+=t;
	}
	while(1){
		for(i=0; i<52; i++) v[i]=-1;
		queue<int> q; q.push(0);
		while(!q.empty()){
			t=q.front(); q.pop();
			for(i=0; i<g[t].size(); i++){
				a=g[t][i];
				if(c[t][a]>f[t][a]&&v[a]==-1){
					q.push(a); v[a]=t;
					if(a==25) break;
				}
			}
		}
		if(v[25]==-1) break;
		m=1e9;
		for(i=25; i!=0; i=v[i])
			m=min(m, c[v[i]][i]-f[v[i]][i]);
		for(i=25; i!=0; i=v[i]){
			f[v[i]][i]+=m;
			f[i][v[i]]-=m;
		}
		ans+=m;
	}
	cout<<ans;
}
