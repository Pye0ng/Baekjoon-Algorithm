#include<stdio.h>
#include<queue>
#define x first
#define y second
using namespace std;
queue<pair<int, int> > q;
char c[3030];
int cnt, d[3030][3030], v[3030][3030];
int dx[]={-1, 1, 0, 0}, dy[]={0, 0, -1, 1};

int main(){
	int n, m, nx, ny, s, i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%s", c);
		for(j=0; j<m; j++){
			d[i][j+1]=c[j]-'0';
			if(d[i][j+1]==2){ q.push({i, j+1}); v[i][j+1]=1; }
		}
	}
	while(!q.empty()){
		s=q.size(); 
		for(i=0; i<s; i++){
			pair<int, int> p=q.front(); q.pop();
			if(d[p.x][p.y]>2){
				printf("TAK\n%d", cnt);
				return 0;
			}
			for(j=0; j<4; j++){
				nx=p.x+dx[j];
				ny=p.y+dy[j];
				if(nx<1||nx>n||ny<1||ny>m||v[nx][ny]||d[nx][ny]==1) continue;
				v[nx][ny]=1;
				q.push({nx, ny});
			}
		}
		cnt++;
	}
	printf("NIE");
}
