#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int abs(int a){ return a>0?a:-a; }
bool cmp(int a, int b){ return a>b; }
vector<int> v;
int c, d[32][100100];

int main(){
	int n, m, t, i, j;
	scanf("%d", &n); v.push_back(501);
	for(i=1; i<=n; i++){
		scanf("%d", &t);
		v.push_back(t);
	}
	sort(v.begin(), v.end(), cmp);
	d[0][0]=1;
	for(i=1; i<=n; i++){
		d[i][0]=1;
		for(j=90001; j>=0; j--)
			if(d[i-1][j]){
				d[i][abs(j-v[i])]=1;
				d[i][j+v[i]]=1; 
				d[i][j]=1;
			}
	}
	scanf("%d", &m);
	while(m--){
		scanf("%d", &t); c=0;
		for(i=1; i<=n; i++)
			if(d[i][t]) c=1;
		if(c) printf("Y ");
		else printf("N ");
	}
}
