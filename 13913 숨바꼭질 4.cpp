#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
queue<int> q, z;
vector<int> v;
int d[100010], ch[100010];

int main(){
	int n, k, s, p, i;
	scanf("%d %d", &n, &k);
	q.push(n);
	while(!q.empty()){
		s=q.size();
		for(i=0; i<s; i++){
			p=q.front(); q.pop();
			if(p==k){ q=z; break; }
			if(p<50001&&!ch[p*2]){ d[p*2]=p; ch[p*2]=1; q.push(p*2); }
			if(p>0&&!ch[p-1]){ d[p-1]=p; ch[p-1]=1; q.push(p-1); }
			if(p<100000&&!ch[p+1]){ d[p+1]=p; ch[p+1]=1; q.push(p+1); }
		}
	}
	while(p!=n){
		v.push_back(p);
		p=d[p];
	}
	printf("%d\n%d ", v.size(), n);
	for(i=v.size()-1; i>=0; i--) printf("%d ", v[i]);
}
