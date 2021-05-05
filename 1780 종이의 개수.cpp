#include<stdio.h>
int n, sum[4], d[2500][2500];

bool check(int x, int y, int size){
	int s=d[x][y];
	for(int i=x; i<x+size; i++)
		for(int j=y; j<y+size; j++)
			if(d[i][j]!=s) return 0;
	return 1;
}

void find(int x, int y, int size){
	if(check(x, y, size)) sum[d[x][y]+1]++;
	else{
		for(int i=x; i<x+size; i+=(size/3))
			for(int j=y; j<y+size; j+=(size/3))
				find(i, j, size/3);
	}
}

int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++) scanf("%d", &d[i][j]);
	find(1, 1, n);
	printf("%d\n%d\n%d", sum[0], sum[1], sum[2]);
}
