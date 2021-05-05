#include<stdio.h>
int n, m, sh, wf, sums, sumw;
int dx[]={-1, 0, 1, 0};
int dy[]={0, -1, 0, 1};
bool visited[300][300];
char map[300][300];

void find(int x, int y){
	visited[x][y]=1;
	if(map[x][y]=='v') wf++;
	else if(map[x][y]=='k') sh++;
	for(int i=0; i<4; i++){
		int ax=x+dx[i];
		int ay=y+dy[i];
		if(ax>=0&&ay>=0&&ax<n&&ay<m&&!visited[ax][ay]&&map[ax][ay]!='#') find(ax, ay);
	}
}

int main(){
	int i, j;
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++) scanf("%s", &map[i]);
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if(map[i][j]!='#'&&!visited[i][j]){
				sh=wf=0;
				find(i, j);
				if(sh>wf) sums+=sh;
				else sumw+=wf;
			}
		}
	}
	printf("%d %d", sums, sumw);
}
