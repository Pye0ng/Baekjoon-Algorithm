#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int, int> > v;
int d[1010][110];

int main(){
	int n, m, k, a, b, i, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		k=0;
		for(j=1; j<=m; j++){
			scanf("%d", &d[i][j]);
			k+=d[i][j];
		}
		v.push_back({k, i});
	}
	sort(v.begin(), v.end());
	for(i=1; i<n; i++){
		a=v[i-1].second; b=v[i].second;
		if(v[i-1].first==v[i].first)
			for(j=1; j<=m; j++)
				if(d[a][j]!=d[b][j]){
					printf("NO");
					return 0;
				}
		else
			for(j=1; j<=m; j++)
				if(d[a][j]==1&&d[b][j]==0){
					printf("NO");
					return 0;
				}
		
	}
	printf("YES");
}
