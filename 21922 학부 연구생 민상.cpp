#include<stdio.h>
#include<vector>
using namespace std;
vector<pair<int, int> > p;
int n, m, cnt, d[2020][2020], v[2020][2020];

void ac(int x, int y, int t){
	int i;
	if(t==0||t==1)
		for(i=x-1; i>0; i--){
			v[i][y]=1;
			if(d[i][y]==3) ac(i, y, 2);
			if(d[i][y]==4) ac(i, y, 4);
			if(d[i][y]!=0&&d[i][y]!=1) break;
		}
	if(t==0||t==2)
		for(i=y+1; i<=m; i++){
			v[x][i]=1;
			if(d[x][i]==3) ac(x, i, 1);
			if(d[x][i]==4) ac(x, i, 3);
			if(d[x][i]!=0&&d[x][i]!=2) break;
		}
	if(t==0||t==3)
		for(i=x+1; i<=n; i++){
			v[i][y]=1;
			if(d[i][y]==3) ac(i, y, 4);
			if(d[i][y]==4) ac(i, y, 2);
			if(d[i][y]!=0&&d[i][y]!=1) break;
		}
	if(t==0||t==4)
		for(i=y-1; i>0; i--){
			v[x][i]=1;
			if(d[x][i]==3) ac(x, i, 3);
			if(d[x][i]==4) ac(x, i, 1);
			if(d[x][i]!=0&&d[x][i]!=2) break;
		}
}

int main(){
	int i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++){
			scanf("%d", &d[i][j]);
			if(d[i][j]==9){
				v[i][j]=1;
				p.push_back({i, j});
			}
		}
	for(i=0; i<p.size(); i++) ac(p[i].first, p[i].second, 0);
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++) cnt+=v[i][j];
	printf("%d", cnt);
}
