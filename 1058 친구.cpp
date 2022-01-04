#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[52];
char s[52];
int mx, vis[52];

void find(int t){
	int f, i; 
	queue<int> q;
	for(i=0; i<v[t].size(); i++){
		q.push(v[t][i]); 
		vis[v[t][i]]=1;
	}
	while(!q.empty()){
		f=q.front(); q.pop();
		for(i=0; i<v[f].size(); i++) vis[v[f][i]]=1;
	}
	return;
}

int main(){
	int n, i, j, cnt;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%s", s);
		for(j=0; j<n; j++)
			if(s[j]=='Y') v[i].push_back(j+1);
	}
	for(i=1; i<=n; i++){
		vis[i]=1; find(i); cnt=0;
		for(j=1; j<=n; j++){
			if(vis[j]&&i!=j) cnt++;
			vis[j]=0;
		}
		if(cnt>mx) mx=cnt;
	}
	printf("%d", mx);
}
