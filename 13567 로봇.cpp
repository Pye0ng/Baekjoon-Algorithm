#include<stdio.h>
#include<string.h>
int dx[]={1, 0, -1, 0};
int dy[]={0, -1, 0, 1};
int x, y, dir;

int main(){
	int n, m, k;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=m; i++){
		char s[5]={};
		scanf("%s", s);
		if(!strcmp(s, "TURN")){
			scanf("%d", &k);
			if(k==1){
				dir++;
				if(dir==4) dir=0;
			}
			else{
				dir--;
				if(dir==-1) dir=3;
			}
		}
		else{
			scanf("%d", &k);
			x+=dx[dir]*k;
			y+=dy[dir]*k;
		}
		if(x<0||y<0||x>n||y>n) {
			printf("-1");
			return 0;
		}
	}
	printf("%d %d", x, y);
}
