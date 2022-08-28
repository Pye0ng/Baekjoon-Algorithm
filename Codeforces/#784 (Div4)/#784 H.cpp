#include<stdio.h>
#include<vector>
#define x first
#define y second
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;

int main(){
	int n, m, t, a, b, i, j;
	int d[32];
	scanf("%d", &t);
	while(t--){
		b=0;
		for(i=0; i<31; i++) d[i]=0;
		scanf("%d %d", &n, &m);
		for(i=0; i<n; i++){
			scanf("%d", &a);
			for(j=0; j<31; j++)
				if(a&(1<<j)) d[j]++;
		}
		for(i=30; i>=0; i--){
			if(m>=(n-d[i])){ m-=(n-d[i]); d[i]=1; }
			else d[i]=0;
		}
		for(i=0; i<31; i++) b+=d[i]*(1<<i);
		printf("%d\n", b);
	}
}
