#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int parent[100010];

int find(int t){
	if(parent[t]<=0) return t;
	else{
		int s=find(parent[t]);
		parent[t]=s;
		return s;
	}
}

void unity(int x, int y){
	x=find(x); y=find(y);
	if(x==y) return;
	if(parent[x]<parent[y]){
		parent[x]+=parent[y];
		parent[y]=x;
	}
	else{
		parent[y]+=parent[x];
		parent[x]=y;
	}
}

int main(){
	int n, m, k, a, b, c, i;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		scanf("%d", &k);
		parent[i]=-k;
	}
	k=n;
	for(i=0; i<m; i++){
		scanf("%d %d %d", &a, &b, &c);
		if(a==1) unity(b, c);
		else{
			b=find(b); c=find(c);
			if(parent[b]<parent[c]){
				parent[b]-=parent[c];
				parent[c]=b;
			}
			else if(parent[b]==parent[c]){
				parent[b]=parent[c]=0;
				k--;
			}
			else{
				parent[c]-=parent[b];
				parent[b]=c;
			}
		}
		k--;
	}
	printf("%d\n", k);
	for(i=1; i<=n; i++)
		if(parent[i]<0) v.push_back(-parent[i]);
	sort(v.begin(), v.end());
	for(i=0; i<v.size(); i++) printf("%d ", v[i]);
}
