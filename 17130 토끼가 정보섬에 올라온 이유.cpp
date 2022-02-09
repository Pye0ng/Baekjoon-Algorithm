#include<stdio.h>
#include<algorithm>
#include<queue>
#define x first
#define y second
using namespace std;
typedef pair<int, int> p;
char c[1010][1010];
int mx, ch, d[1010][1010];
int dx[]={-1, 0, 1};
queue<p> q;

int main(){
	int n, m, nx, ny, i, j;
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++) scanf("%s", c[i]);
	for(i=0; i<n; i++)
		for(j=0; j<m; j++){
			if(c[i][j]=='R') q.push({i, j});
			else d[i][j]=-1;
		}
	while(!q.empty()){
		p t=q.front(); q.pop();
		for(i=0; i<3; i++){
			nx=t.x+dx[i];
			ny=t.y+1;
			if(nx<0||nx>=n||ny<0||ny>=m||c[nx][ny]=='#') continue;
			if(c[nx][ny]=='C'&&d[nx][ny]<d[t.x][t.y]+1){
				d[nx][ny]=d[t.x][t.y]+1;
				q.push({nx, ny});
			}
			if(c[nx][ny]=='O'&&(d[nx][ny]<d[t.x][t.y])){
				ch=1; d[nx][ny]=d[t.x][t.y];
				mx=max(d[nx][ny], mx);
				q.push({nx, ny});
			}
			if(c[nx][ny]=='.'&&(d[nx][ny]<d[t.x][t.y])){
				d[nx][ny]=d[t.x][t.y];
				q.push({nx, ny});
			}
		}
	}
	if(ch) printf("%d", mx);
	else printf("-1");
}
