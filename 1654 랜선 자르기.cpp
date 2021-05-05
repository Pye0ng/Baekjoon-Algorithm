#include<stdio.h>
#include<algorithm>
using namespace std;
int a[10001], n, k;

int main(){
	long long int p, q, sum, g;
	scanf("%d %d", &k, &n);
	for(int i=0; i<k; i++) scanf("%d", &a[i]);
	sort(a, a+k);
	p=1; q=a[k-1];
	while(p<=q){
		g=(p+q)/2;
		sum=0;
		for(int i=0; i<k; i++) sum+=a[i]/g;
		if(sum>=n) p=g+1;
		else q=g-1; 	
	}
	printf("%lld", q);
}
