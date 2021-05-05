#include<stdio.h>
#include<memory.h>
#include<vector>
using namespace std;
vector<int> v; 
 
int c[110][110];
bool visited[110][110];
int n, m, t;
int dx[]={-1, 0, 0, 1};
int dy[]={0 ,1, -1, 0};

int ch(){
	int sum=0; 
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++) if(c[i][j]==1) sum++;
	return sum;  
}

void air(int x, int y){
	visited[x][y]=1;
	c[x][y]=2;
	for(int i=0; i<4; i++){
		int ax=x+dx[i]; 
		int ay=y+dy[i];
		if(ax<0||ay<0||ax>=n||ay>=m) continue;
		if(c[ax][ay]==1||visited[ax][ay]) continue;
		air(ax, ay);
	}
}

bool melt(int x, int y){
	if(c[x-1][y]==2||c[x+1][y]==2||c[x][y-1]==2||c[x][y+1]==2) return 1;
	else return 0;
}

int main(){
	int i, j;
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++)
		for(j=0; j<m; j++) scanf("%d", &c[i][j]);
	while(ch()!=0){
		t++;
		memset(visited, 0, sizeof(visited));
		air(0, 0);
		v.push_back(ch());
		for(i=1; i<n; i++){
			for(j=1; j<m; j++)
				if(melt(i, j)&&c[i][j]==1) c[i][j]=0;
		}
	}
	printf("%d %d", t, v[t-1]);
	return 0;
}
