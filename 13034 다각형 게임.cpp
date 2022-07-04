#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int d[1010];

int main(){
	int n, c, i, j;
	scanf("%d", &n);
	d[2]=1;
	for(i=3; i<=n; i++){
		vector<int> g; c=1;
		for(j=1; j<=i/2; j++) g.push_back(d[j-1]^d[i-j-1]);
		sort(g.begin(), g.end());
		g.erase(unique(g.begin(), g.end()), g.end());
		for(j=0; j<g.size(); j++)
			if(j!=g[j]){
				d[i]=j; c=0;
				break;
			}
		if(c) d[i]=g.size();
	}
	printf("%d", d[n]?1:2);
}
