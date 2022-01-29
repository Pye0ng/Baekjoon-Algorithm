#include<stdio.h>
#include<queue>
using namespace std;
struct p{ int x, y, z; };
queue<p> q;
int a, b, v[3010][3010];

int main(){
	int n, k, i; char c[3010]; p t;
	scanf("%d %d", &n, &k);
	scanf("%s", c);
	for(i=0; i<n; i++){
		if(c[i]=='H') a++;
		else b++;
	}
	t.x=a; t.y=b; t.z=0;
	q.push(t); v[a][b]=1;
	while(!q.empty()){
		t=q.front(); q.pop();
		if(t.y==n){
			printf("%d", t.z);
			return 0;
		}
		p s; s.z=t.z+1;
		for(i=0; i<=k; i++){
			if(t.x<i||t.y<k-i) continue;
			s.x=t.x+k-2*i; s.y=t.y+2*i-k;
			if(v[s.x][s.y]) continue;
			q.push(s); v[s.x][s.y]=1;
		}
	}
	printf("-1");
}
