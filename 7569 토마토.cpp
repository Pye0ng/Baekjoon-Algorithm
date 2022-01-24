#include<stdio.h>
#include<queue>
using namespace std;
struct p{ int x, y, z; };
int t, h, n, m, d[110][110][110], visit[110][110][110];
queue<p> q;

void bfs(int i, int j, int k){
	if(i<1||i>h||j<1||j>n||k<1||k>m||visit[i][j][k]||d[i][j][k]!=0) return;
	visit[i][j][k]=1;
	p s; s.x=i; s.y=j; s.z=k;
	q.push(s); d[i][j][k]=1;
}

int main(){
	int i, j, k;
	scanf("%d %d %d", &m, &n, &h);
	for(i=1; i<=h; i++)
		for(j=1; j<=n; j++)
			for(k=1; k<=m; k++){
				scanf("%d", &d[i][j][k]);
				if(d[i][j][k]!=0) visit[i][j][k]=1;
				if(d[i][j][k]==1){
					p s; s.x=i; s.y=j; s.z=k;
					q.push(s);
				}
			}
	while(!q.empty()){
		int s=q.size();
		for(i=0; i<s; i++){
			p f=q.front(); q.pop();
			bfs(f.x-1, f.y, f.z);
			bfs(f.x+1, f.y, f.z);
			bfs(f.x, f.y-1, f.z);
			bfs(f.x, f.y+1, f.z);
			bfs(f.x, f.y, f.z-1);
			bfs(f.x, f.y, f.z+1);
		}
		t++;
	}
	for(i=1; i<=h; i++)
		for(j=1; j<=n; j++)
			for(k=1; k<=m; k++)
				if(visit[i][j][k]==0){
					printf("-1");
					return 0;
				}
	printf("%d", t-1);
}
