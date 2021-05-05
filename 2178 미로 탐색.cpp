#include<stdio.h>
#include<queue>
using namespace std; 
int n, m, cnt;
char c[110][110];
bool visited[110][110];

int dx[]={-1, 0, 1, 0};
int dy[]={0, -1, 0, 1};

void find(int x, int y){
	queue<pair<int, int> > q;
	q.push({x, y});
	visited[x][y]=1;
	while(!q.empty()){
		int s=q.size();
		cnt++;
		for(int i=1; i<=s; i++){
			int a=q.front().first, b=q.front().second;
			q.pop();
			if(a==n-1&&b==m-1) return;
			for(int j=0; j<4; j++){
				int ax=a+dx[j];
				int ay=b+dy[j];
				if(ax<0||ay<0||ax>=n||ay>=m) continue;
				if(!visited[ax][ay]&&c[ax][ay]==49){
					q.push({ax, ay});
					visited[ax][ay]=1;
				}
			}
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) scanf("%s", c[i]);
	find(0, 0);
	printf("%d", cnt);
}
