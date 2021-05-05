#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
char c[30][30];
bool map[30][30], visited[30][30];
int n, sum, cnt;

int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};

void dfs(int x, int y){
	visited[x][y]=1;
	sum++;
	for(int i=0; i<4; i++){
		int ax=x+dx[i];
		int ay=y+dy[i];
		if(ax<0||ay<0||ax>=n||ay>=n) continue;
		if(map[ax][ay]&&!visited[ax][ay]) dfs(ax, ay);
	}
}

int main(){
	int i, j;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%s", c[i]);
	for(i=0; i<n; i++)
		for(j=0; j<n; j++) map[i][j]=c[i][j]-48;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(map[i][j]&&!visited[i][j]){
				sum=0;
				dfs(i, j);
				v.push_back(sum);
				cnt++;
			}
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n", cnt);
	for(i=0; i<v.size(); i++) printf("%d\n", v[i]);
}
