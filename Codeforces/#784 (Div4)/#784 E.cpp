#include<stdio.h>
#include<vector>
#define x first
#define y second
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int main(){
	int n, t, a, b, i, j;
	ll d[15][15], ans;
	scanf("%d", &t);
	char c[100100][3];
	while(t--){
		for(i=0; i<11; i++)
			for(j=0; j<11; j++) d[i][j]=0;
		ans=0;
		scanf("%d", &n);
		for(i=0; i<n; i++){
			scanf("%s", c[i]);
			d[c[i][0]-'a'][c[i][1]-'a']++;
		}
		for(i=0; i<n; i++){
			a=c[i][0]-'a'; b=c[i][1]-'a';
			for(j=0; j<11; j++)
				if(j!=b) ans+=d[a][j];
			for(j=0; j<11; j++)
				if(j!=a) ans+=d[j][b];
			d[a][b]--;
		}
		printf("%lld\n", ans);
	}
}
