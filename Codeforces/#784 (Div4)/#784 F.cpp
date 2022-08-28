#include<stdio.h>
#include<vector>
#define x first
#define y second
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int main(){
	int n, m, t, p, q, s, a, b, i;
	int d[202000];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n); m=0;
		for(i=1; i<=n; i++) scanf("%d", &d[i]);
		p=1; q=n; a=d[1]; b=d[n]; s=2;
		while(p<q){
			if(a==b){ m=s++; a+=d[++p]; }
			else if(a<b){ a+=d[++p]; s++; }
			else{ b+=d[--q]; s++; }
		}
		printf("%d\n", m);
	}
}
