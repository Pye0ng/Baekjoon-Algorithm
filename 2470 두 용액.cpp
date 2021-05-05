#include<stdio.h>
#include<math.h>
#include<algorithm>
int a[100001];
int n, mn=2000000000;

int main(){
	int i, j;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &a[i]);
	std::sort(a, a+n);
	if(a[n-1]<=0){
		printf("%d %d", a[n-2], a[n-1]);
		return 0;
	}
	if(a[0]>=0){
		printf("%d %d", a[0], a[1]);
		return 0;
	}
	int p=0, q=n-1, r, l;
	while(p<q){
		if(mn>abs(a[p]+a[q])){
			r=p; l=q;
			mn=abs(a[p]+a[q]);
		}
		if(mn==0){
			printf("%d %d", a[r], a[l]);
			return 0;
		}
		if(a[p]+a[q]>0) q--;
		else p++;
	}
	printf("%d %d", a[r], a[l]);
}

