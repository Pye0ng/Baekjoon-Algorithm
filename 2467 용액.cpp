#include<stdio.h>
#include<math.h>
int k=1, a[100001], min=2000000000;

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &a[i]);	
	if(a[n]<=0){
		printf("%d %d", a[n-1], a[n]);
		return 0;
	}
	if(a[1]>=0){
		printf("%d %d", a[1], a[2]);
		return 0;
	}
	int p=1, q=n, r, l;
	while(p<q){
		if(min>abs(a[p]+a[q])){
			r=p; l=q;
			min=abs(a[p]+a[q]);
		}
		if(min==0){
			printf("%d %d", a[r], a[l]);
			return 0;
		}
		if(a[p]+a[q]>0) q--;
		else p++;
	}
	printf("%d %d", a[r], a[l]);
}
