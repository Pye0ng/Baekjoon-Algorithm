#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int d[2020];

int main(){
	int n, c, i, j;
	scanf("%d", &n);
	d[1]=d[2]=d[3]=1;
	d[4]=d[5]=2;
	for(i=6; i<=n; i++){
		vector<int> g; c=1;
		for(j=1; j<=(i+1)/2; j++){
			if(j<=3) g.push_back(d[i-j-2]);
			else g.push_back(d[j-3]^d[i-j-2]);
		}
		sort(g.begin(), g.end());
		g.erase(unique(g.begin(), g.end()), g.end()); 
		for(j=0; j<g.size(); j++)
			if(j!=g[j]){
				d[i]=j;
				c=0; break;
			}
		if(c) d[i]=g.size();
	}
	printf("%d", d[n]?1:2);
}
