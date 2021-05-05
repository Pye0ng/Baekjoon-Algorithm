#include<stdio.h>
#include<memory.h>
int n, cnt; 
bool ch, g[101][101], ans[101][101], visited[101];

void find(int s, int k){
	if(s==k){ 
		if(cnt==0) goto go;
		ch=1;
		return;
	}
	visited[s]=1;
	go:
	cnt++;
	for(int i=1; i<=n; i++)
		if(g[s][i]&&!visited[i]) find(i, k);
}

int main(){
	int i, j;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++) scanf("%d", &g[i][j]);
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			ch=0; cnt=0;
			find(i, j);
			if(ch) ans[i][j]=1;
			memset(visited, 0, sizeof(visited));
		}
	}
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++) printf("%d ", ans[i][j]);
		printf("\n");
	}
}
