#include<stdio.h>
#include<algorithm>
using namespace std;
int ans, mn;

int main(){
	int n, t, i;
	scanf("%d", &n);
	scanf("%d", &mn);
	printf("0 ");
	for(i=1; i<n; i++){
		scanf("%d", &t);
		ans=max(ans, t-mn);
		printf("%d ", ans);
		mn=min(mn, t);
	}
}
