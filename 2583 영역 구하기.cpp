#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool map[101][101], visited[101][101];
int n, m, k, cnt;
vector<int> v;

int dx[]={-1, 0, 0, 1};
int dy[]={0, -1, 1, 0};

void dfs(int x, int y){
	visited[x][y]=1;
	k++;
	for(int i=0; i<4; i++){
		int ax=x+dx[i];
		int ay=y+dy[i];
		if(ax<=0||ay<=0||ax>n||ay>m) continue;
		if(!map[ax][ay]&&!visited[ax][ay]) dfs(ax, ay);
	}
}

int main(){
	int i, j, p;
	int x1, x2, y1, y2;
	scanf("%d %d %d", &n, &m, &k);
	for(i=1; i<=k; i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for(j=y1+1; j<=y2; j++)
			for(p=x1+1; p<=x2; p++) map[j][p]=1;
	}
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++){
			k=0;
			if(!map[i][j]&&!visited[i][j]){
				cnt++;
				dfs(i, j);
				v.push_back(k);
			}
		}
		
	sort(v.begin(), v.end());
	printf("%d\n", cnt);
	for(i=0; i<v.size(); i++) printf("%d ", v[i]);
}
