#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
	int n, a, b, i;
	scanf("%d %d", &n, &a);
	for(i=1; i<n; i++) scanf("%d", &b);
	if(a<b) swap(a, b);
	if(a-b>=n-2) printf("%d", a-n+2);
	else printf("%d", b-(n-1-a+b)/2);
}
