#include<stdio.h>
#include<algorithm>
#define M -1000000001
using namespace std;
typedef pair<int, int> P;
P t, d[1000010];
int cnt;

int main(){
	int n, i; t={M, M};
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d %d", &d[i].first, &d[i].second);
	sort(d+1, d+n+1);
	for(i=1; i<=n; i++){
		if(t.second<d[i].first){
			cnt+=t.second-t.first;
			t=d[i];
		}
		else t.second=max(t.second, d[i].second);
	}
	cnt+=t.second-t.first;
	printf("%d", cnt);
}
