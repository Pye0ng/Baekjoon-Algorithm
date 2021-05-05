#include<iostream>
using namespace std;
bool ch, map[1001][1001], visited[1001][1001];
char c[1001][1001];
int n, m;

int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};

void dfs(int x, int y){
	if(x==n){
		ch=1;
		return;
	}
	visited[x][y]=1;
	for(int i=0; i<4; i++){
		int ax=x+dx[i];
		int ay=y+dy[i];
		if(ax<=0||ay<0||ax>n||ay>=m) continue;
		if(!map[ax][ay]&&!visited[ax][ay]) dfs(ax, ay); 
	}
}

int main(){
	int i, j;
	cin>>n>>m;
	for(i=1; i<=n; i++) cin>>c[i];
	for(i=1; i<=n; i++)
		for(j=0; j<m; j++) map[i][j]=(c[i][j]=='1');
	for(i=0; i<m; i++){
		if(!map[1][i]&&!visited[1][i]) dfs(1, i);
		if(ch){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
}
