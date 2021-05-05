#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000001], n, m, h;

void bs(int p, int q){
	if(p==q-1) return;
	int g=(p+q)/2;
	long long int sum=0;
	for(int i=0; i<n; i++){ if(a[i]>g) sum+=(a[i]-g); }
	if(sum>=m){
		if(g>=h) h=g;
		bs(g, q);
	}
	else bs(p, g);
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	sort(a, a+n);
	bs(0, a[n-1]);
	printf("%d", h);
}
