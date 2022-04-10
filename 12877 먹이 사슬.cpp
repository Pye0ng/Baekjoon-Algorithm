#include<stdio.h>
int p[150300];

int find(int t){
	if(p[t]<0) return t;
	return p[t]=find(p[t]);
}

void unite(int x, int y){
	x=find(x); y=find(y);
	if(x==y) return;
	if(p[x]<=p[y]){ p[x]+=p[y]; p[y]=x; }
	else{ p[y]+=p[x]; p[x]=y; }
}

bool S(int a, int b){ return find(a)==find(b); }

int main(){
	int n, k, a, b, c, m=0, i;
	scanf("%d %d", &n, &k);
	for(i=0; i<3*n+10; i++) p[i]=-1;
	while(k--){
		scanf("%d %d %d", &a, &b, &c);
		b--; c--;
		if(b>=n||c>=n||b<0||c<0){
			m++;
			continue;
		}
		if(a&1){
			if(S(b*3, c*3+1)||S(b*3, c*3+2)) m++;
			else{
				unite(b*3, c*3);
				unite(b*3+1, c*3+1);
				unite(b*3+2, c*3+2);
			}
		}
		else{
			if(S(b*3, c*3)||S(b*3, c*3+2)) m++;
			else{
				unite(b*3, c*3+1);
				unite(b*3+1, c*3+2);
				unite(b*3+2, c*3);
			}
		}
	}
	printf("%d", m);
}
