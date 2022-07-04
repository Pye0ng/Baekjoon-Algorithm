#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int p[40], d[3000300];
vector<int> g;

int main(){
	int n, t, i, j;
	p[1]=p[2]=1;
	for(i=3; i<34; i++) p[i]=p[i-1]+p[i-2];
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &t);
		g.push_back(t);
	}
	d[1]=1; d[2]=2; d[3]=3;
	sort(g.begin(), g.end());
	for(i=4; i<=g[g.size()-1]; i++){
		vector<int> v(18, 0); t=1;
		while(p[++t]<=i) v[d[i-p[t]]]=1;
		for(j=0; j<v.size(); j++)
			if(!v[j]){
				d[i]=j;
				break;
			}
	} 
	t=0;
	for(i=0; i<n; i++) t^=d[g[i]];
	printf("%s", t?"koosaga":"cubelover");
} 
