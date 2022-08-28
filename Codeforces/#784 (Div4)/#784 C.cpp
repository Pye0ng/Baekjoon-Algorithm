#include<stdio.h>
#include<vector>
#define x first
#define y second
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int main(){
	int n, m, t, a, b, i;
	int d[202000];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n); m=1;
		for(i=1; i<=n; i++) scanf("%d", &d[i]);
		a=d[1]&1; b=d[2]&1;
		for(i=1; i<=n; i+=2)
			if(a!=(d[i]&1)) m=0;
		for(i=2; i<=n; i+=2)
			if(b!=(d[i]&1)) m=0;
		printf("%s\n", m?"YES":"NO");
	}
}
