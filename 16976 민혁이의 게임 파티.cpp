#include<stdio.h>
#include<vector>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> pii;
vector<int> f[100100], g[100100];
int p[100100], l[100100], r[100100], a[100100];

int find(int t){ return p[t]<0?t:p[t]=find(p[t]); }

void unite(int a, int b){
	a=find(a); b=find(b);
	if(a!=b){
		if(p[a]>p[b]) swap(a, b);
		p[a]+=p[b]; p[b]=a;
	}
}

int main(){
	int n, m, q, t, i, j, k;
	bool ch1, ch2;
	scanf("%d %d %d", &n, &m, &q);
	for(i=1; i<=n; i++){
		scanf("%d", &t);
		f[t-1].push_back(i);
	}
	vector<pii> qr(q);
	for(i=0; i<q; i++) scanf("%d %d", &qr[i].x, &qr[i].y);
	for(i=0; i<m; i++){ l[i]=1; r[i]=q; }
	while(1){
		for(i=1; i<=q; i++) g[i].clear();
		for(i=0; i<100010; i++) p[i]=-1;
		ch1=0;
		for(i=0; i<m; i++)
			if(l[i]<=r[i]){
				ch1=1;
				g[(l[i]+r[i])/2].push_back(i);
			}
		if(!ch1) break;
		for(i=0; i<q; i++){
			unite(qr[i].x, qr[i].y);
			for(j=0; j<g[i+1].size(); j++){
				t=g[i+1][j]; ch2=1;
				for(k=0; k<f[t].size()-1; k++)
					if(find(f[t][k])!=find(f[t][k+1])) ch2=0;
				if(ch2){ r[t]=i; a[t]=i+1; }
				else l[t]=i+2;
			}
		}
	}
	for(i=0; i<m; i++){
		if(f[i].size()==1) printf("0\n");
		else if(l[i]>q) printf("-1\n");
		else printf("%d\n", a[i]);
	}
}
