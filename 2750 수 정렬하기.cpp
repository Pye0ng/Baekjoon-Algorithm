#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1001];

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &a[i]);
	sort(a, a+n);
	for(i=0; i<n; i++) printf("%d\n", a[i]);
}
