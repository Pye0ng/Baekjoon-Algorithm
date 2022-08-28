#include<stdio.h>
#include<vector>
#define x first
#define y second
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int main(){
	int n, m, t, c, i;
	int d[202000];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n); c=-1;
		for(i=1; i<=n; i++) d[i]=0;
		for(i=1; i<=n; i++){
			scanf("%d", &m);
			d[m]++;
			if(d[m]>=3) c=m;
		}
		printf("%d\n", c);
	}
}
