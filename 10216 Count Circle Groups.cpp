#include<stdio.h>
int p[3030], x[3030], y[3030], r[3030];

int d(int t){ return t*t; }

int find(int t){
	if(p[t]<0) return t;
	return p[t]=find(p[t]);
}

void unite(int x, int y){
	x=find(x); y=find(y);
	if(x==y) return;
	if(p[x]<p[y]){
		p[x]+=p[y];
		p[y]=x;
	}
	else{
		p[y]+=p[x];
		p[x]=y;
	}
}

int main(){
	int t, n, c, i, j;
	scanf("%d", &t);
	while(t--){
		c=0;
		scanf("%d", &n);
		for(i=1; i<=n; i++) p[i]=-1;
		for(i=1; i<=n; i++) scanf("%d %d %d", &x[i], &y[i], &r[i]);
		for(i=1; i<=n; i++)
			for(j=i+1; j<=n; j++)
				if(d(x[j]-x[i])+d(y[j]-y[i])<=d(r[j]+r[i])) unite(i, j);
		for(i=1; i<=n; i++)
			if(p[i]<0) c++;
		printf("%d\n", c);
	}
}
