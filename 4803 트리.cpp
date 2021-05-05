#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

int main(){
	int n, m, t=0, i, j;
	scanf("%d %d", &n, &m);
	while(n!=0||m!=0){	//간선의 개수가 0일 수도 있다.. 
		vector<int> v[1020]; int cnt=0;
		queue<int> q; bool visited[1020];
		for(i=0; i<=1000; i++) visited[i]=false;
		for(i=0; i<m; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(i=1; i<=n; i++){
			int e=0, ve=0;
			if(visited[i]==false){
				q.push(i); cnt++;
				while(!q.empty()){
					int nw=q.front(); q.pop();
					if(visited[nw]) continue;
					ve++; visited[nw]=1;
					for(j=0; j<v[nw].size(); j++){ e++; q.push(v[nw][j]); }
				}
				if(e/2!=ve-1) cnt--;
				e=0; ve=0;
			}
		}
		if(cnt>=2) printf("Case %d: A forest of %d trees.\n", ++t, cnt);
        else if(cnt==1) printf("Case %d: There is one tree.\n", ++t);
        else printf("Case %d: No trees.\n", ++t);
		scanf("%d %d", &n, &m);
	}
}
