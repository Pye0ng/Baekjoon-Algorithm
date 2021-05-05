#include<iostream>
using namespace std;
char c[350][350];
bool visited[350][350];
int n, m, sumw, sums;

int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};

void dfs(int x, int y){
	if(c[x][y]=='#'||visited[x][y]) return;
 	visited[x][y]=1;
	if(c[x][y]=='v') sumw++;
	else if(c[x][y]=='o') sums++;
	for(int i=0; i<4; i++){
		int ax=x+dx[i];
		int ay=y+dy[i];
		if(ax<0||ay<0||ax>=n||ay>=m) continue;
		if(c[ax][ay]=='#'||visited[ax][ay]) continue;
		dfs(ax, ay);
	}
}

int main(){
	int i, j, wf=0, sh=0;
	cin>>n>>m;
	for(i=0; i<n; i++) cin>>c[i];
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			sumw=0; sums=0;
			if(c[i][j]!='#'&&!visited[i][j]){
				dfs(i, j);
				if(sumw<sums) sh+=sums;
				else wf+=sumw;
			}
		}
	}
	cout<<sh<<' '<<wf;
} 
