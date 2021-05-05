#include<stdio.h>
char a, b, c[110][110];
int n, cnty, cntn, visitedy[110][110], visitedn[110][110];
int dx[]={-1, 0, 1, 0};
int dy[]={0, -1, 0, 1};

void findy(int x, int y){
	visitedy[x][y]=1;
	if(a=='B'){
		for(int i=0; i<4; i++){
			int ax=x+dx[i];
			int ay=y+dy[i];
			if(ax<0||ay<0||ax>=n||ay>=n) continue;
			if(visitedy[ax][ay]==0&&c[ax][ay]=='B') findy(ax, ay);
		}
	}
	else{
		for(int i=0; i<4; i++){
			int ax=x+dx[i];
			int ay=y+dy[i];
			if(ax<0||ay<0||ax>=n||ay>=n) continue;
			if(visitedy[ax][ay]==0&&c[ax][ay]!='B') findy(ax, ay);
		}
	}
}

void findn(int x, int y){
	visitedn[x][y]=1;
	if(b=='B'){
		for(int i=0; i<4; i++){
			int ax=x+dx[i];
			int ay=y+dy[i];
			if(ax<0||ay<0||ax>=n||ay>=n) continue;
			if(visitedn[ax][ay]==0&&c[ax][ay]=='B') findn(ax, ay);
		}
	}
	else if(b=='R'){
		for(int i=0; i<4; i++){
			int ax=x+dx[i];
			int ay=y+dy[i];
			if(ax<0||ay<0||ax>=n||ay>=n) continue;
			if(visitedn[ax][ay]==0&&c[ax][ay]=='R') findn(ax, ay);
		}
	}
	else{
		for(int i=0; i<4; i++){
			int ax=x+dx[i];
			int ay=y+dy[i];
			if(ax<0||ay<0||ax>=n||ay>=n) continue;
			if(visitedn[ax][ay]==0&&c[ax][ay]=='G') findn(ax, ay);
		}
	}
}

int main(){
	int i, j;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%s", c[i]);
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(visitedy[i][j]==0){
				cnty++;
				a=c[i][j];
				findy(i, j);
			}
			if(visitedn[i][j]==0){
				cntn++;
				b=c[i][j];
				findn(i, j);
			}
		}
	}
	printf("%d %d", cntn, cnty);
} 
