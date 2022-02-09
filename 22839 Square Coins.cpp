#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int d[310];

int main(){
	int n, m, i, j;
	scanf("%d", &m); d[0]=1;
	for(i=1; i<18; i++) v.push_back(i*i);
	while(m){
		n=upper_bound(v.begin(), v.end(), m)-v.begin();
		for(i=0; i<n; i++)
			for(j=1; j<=m; j++)
				if(j>=v[i]) d[j]+=d[j-v[i]];
		printf("%d\n", d[m]);
		for(i=1; i<=m; i++) d[i]=0;
		scanf("%d", &m);
	}
}
